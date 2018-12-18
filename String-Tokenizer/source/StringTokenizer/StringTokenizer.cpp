#include"StringTokenizer.h"
#include<cstring>

StringTokenizer::StringTokenizer(const char *string, const char *delim)
{
	tokens = new char[strlen(string)]; 
	char *p = tokens;
	char *delims = new char[strlen(delim)];
	char *t = delims;
	ntokens = 0;

	//parse delim
	p = (char*)delim;
	while (*p)
	{
		if (*p == '\\')
		{
			p++;
			switch(*p)
			{
				case 'n': *t = '\n';
						  t++;
						  break;
				case 't': *t = '\t';
						  t++;
						  break;
				case '\\': *t = '\\';
						  t++;
						  break;
				default: *t = *p;
						  t++;
			}
		}
		else {
			*t = *p;
			t++;
		}
		p++;
	}

	p = tokens; 

	while (*string)
	{
		if (in(*string, delims))
		{
			*p = 0;
			while (in (*string, delims)) string ++;
			p++;
			ntokens ++;
			continue;
		}
		*(p++) = *string;
		string ++;
	}
	ntokens ++;
	currToken = tokens;
	*p = 0;
	delete delims;
}

StringTokenizer::~StringTokenizer()
{
	if (tokens != NULL)
		delete tokens;
}


bool StringTokenizer::in(char a, const char *string)
{
	while (*string)
	{
		if (a == *string)
			return true;
		string ++;
	}
	return false;
}

bool StringTokenizer::hasToken()
{
	return ntokens;
}

const char* StringTokenizer::nextToken()
{
	char *p = currToken;
	while (*(currToken++));
	ntokens --;
	return p;
}
