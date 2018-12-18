# StringTokenizer
## Class Members : StringTokenizer
### Public Datatypes
None
### Public Methods
<h4> StringTokenizer(const char *string, const char *delims) </h4>
<i>Constructor</i>. It constructs a StringTokenizer object by parsing <i>string</i>. The tokens are assumed to be delimited by delimeters mentioned in <i>delims</i>. Every character in <i>delims</i> is considered to be a delimiter.</br>
C-style escape characters are also allowed (not all of them):</br>
<ul>
	<li>\n: New line characyer</li>
	<li>\t: tab character</li>
	<li>\\: \ character</li>
	<li>Any other character is simply interpreted as such. For eg: \a is same as a.</li>
</ul>
<h4> ~StringTokenizer() </h4>
<i>Destructor</i>
<h4> bool hasToken() </h4>
returns if there is a token available to read.
<h4> const char * nextToken() </h4>
returns the next token read. If there are no tokens left result is undefined. Hence, always use <i>hasToken()</i> before invoking <i>nextToken()</i>


## Example code snippet

<h4>source</h4>

```c++
#include<StringTokenizer.h>
#include<iostream>

using namespace std;

int main()
{
	char text[] = "Hello this is a test.";
	StringTokenizer tokens(text, " e");
	while (tokens.hasToken())
	{
		cout << tokens.nextToken() << endl;
	}
	return 0;
}
```

<h4>output</h4>

```
H
llo
this
is
a
t
st.
```
