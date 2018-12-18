# StringTokenizer
## Class Members : StringTokenizer
### Public Datatypes
None
### Public Methods
#### StringTokenizer(const char *string, const char *delims)
<i>Constructor</i>. It constructs a StringTokenizer object by parsing <i>string</i>. The tokens are assumed to be delimited by delimeters mentioned in <i>delims</i>. Every character in <i>delims</i> is considered to be a delimiter.</br>
C-style escape characters are also allowed (not all of them):</br>
<ul>
	<li>\n: New line characyer</li>
	<li>\t: tab character</li>
	<li>\\: \ character</li>
	<li>Any other character is simply interpreted as such. For eg: \a is same as a.</li>
</ul>
#### ~StringTokenizer()
<i>Destructor</i>
#### bool hasToken()
returns if there is a token available to read.
#### const char * nextToken()
returns the next token read. If there are no tokens left result is undefined. Hence, always use <i>hasToken()</i> before invoking <i>nextToken()</i>
