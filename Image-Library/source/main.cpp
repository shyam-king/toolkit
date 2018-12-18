#include<iostream>
#include <Image.h>

using namespace std;

int main()
{
	using namespace Image::PNG;
	using namespace Image;
	HANDLE *png_file = new(nothrow) HANDLE("file.png");

	png_file -> readHeader();

	uint32_t width = png_file -> width();
	uint32_t height = png_file -> height();

	cout << png_file -> width() << endl;
	cout << png_file -> height() << endl;
	cout << png_file -> bitDepth() << endl;
	cout << png_file -> colorType() << endl;

	png_file -> loadData();

	chunkRGB_8 *data = NULL;
	data = png_file -> data<chunkRGB_8>();




	delete png_file;
	return 0;
}
