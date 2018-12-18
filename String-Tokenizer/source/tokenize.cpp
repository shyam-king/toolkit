#include<iostream>
#include<StringTokenizer.h>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{
	int inputFiles = 0;
	if (argc < 2)
	{
		cerr << "Usage:\n";
		cerr << "\t" << argv[0] << " <delims> [source1 source2 ...]\n";
		return 1;
	}
	else if (argc >= 3)
	{
		inputFiles = argc - 2;
	}

	const char *delims = argv[1];
	char *line = new char[256];

	if (!inputFiles)
	{
		while (cin.getline(line, 256))
		{
			StringTokenizer S(line, delims);
			while (S.hasToken())
				cout << S.nextToken() << endl;
		}
	}
	else
	{
		for (int i = 0; i < inputFiles; i++)
		{
			ifstream file(argv[2+i]);

			while (file.getline(line, 256))
			{
				StringTokenizer S(line, delims);
				while (S.hasToken())
					cout << S.nextToken() << endl;
			}

			file.close();
		}
	}

	delete line;
	return 0;
}
