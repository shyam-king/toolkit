class StringTokenizer{
	char *tokens; //all tokens
	int ntokens;
	unsigned long size; //the size in bytes of the whole token string
	char *currToken;
	bool in(char, const char*);
	public:
	StringTokenizer(const char*, const char *delim);
	~StringTokenizer();
	bool hasToken();
	const char* nextToken();
};
