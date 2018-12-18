#include<iostream>
#include <Image.h>

using namespace std;

int main()
{
	using namespace Image::PNG;
	HANDLE *png_file = new(nothrow) HANDLE("file.png");
	if (!png_file)
	{
		cout << "error occured";
		return 0;
	}

	png_file -> readHeader();

	cout << *((uint32_t*)(png_file -> width().dataptr)) << endl;
	cout << *((uint32_t*)(png_file -> height().dataptr)) << endl;

	delete png_file;
	return 0;
}
