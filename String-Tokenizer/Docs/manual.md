# StringTokenizer
## Class Members : STringTokenizer
### Public Datatypes
None
### Public Methods
<b>StringTokenizer(const char *string, const char *delims)</b></br>
</br>
<i>Constructor</i>. It constructs a StringTokenizer object by parsing <i>string</i>. The tokens are assumed to be delimited by delimeters mentioned in <i>delims</i>. Every character in <i>delims</i> is considered to be a delimiter.</br>
C-style escape characters are also allowed (not all of them):</br>
<ul>
	<li>\n: New line characyer</li>
	<li>\t: tab character</li>
	<li>\\: \ character</li>
	<li>Any other character is simply interpreted as such. For eg: \a is same as a.</li>
</ul>
