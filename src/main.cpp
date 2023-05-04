#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace fractal;


int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			bitmap.setPixel(i, j, 0xFF, 0x0, 0x0);
		}
	}
	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 0xFF, 0xFF, 0xFF);

	bitmap.write("test.bmp");

	cout << "Image created." << endl;
	return 0;
}
