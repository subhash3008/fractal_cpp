#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "MandelBrot.h"
#include "ZoomList.h"

using namespace std;
using namespace fractal;


int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	// double min = 999999;
	// double max = -999999;

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, (4.0 / WIDTH)));
	zoomList.add(Zoom(101, HEIGHT - 284, .1));
	zoomList.add(Zoom(679, HEIGHT - 379, .05));
	zoomList.add(Zoom(420, HEIGHT - 326, .05));

	unique_ptr<int[]> histogram(new int[MandelBrot::MAX_ITERATIONS]{0});
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			// bitmap.setPixel(x, y, 0xFF, 0x0, 0x0);
			pair<double, double> coords = zoomList.doZoom(x, y);


			int iterations = MandelBrot::getIterations(
					coords.first,
					coords.second);

			fractal[y*WIDTH + x] = iterations;

			if (iterations != MandelBrot::MAX_ITERATIONS) {
				histogram[iterations]++;;
			}
		}
	}

	long int sum = 0;
	for (int i = 0; i < MandelBrot::MAX_ITERATIONS; ++i) {
		sum += histogram[i];
	}

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];

			// for test.bmp
			// uint8_t color = (uint8_t)(256 *
			//		((double)(iterations) / MandelBrot::MAX_ITERATIONS));
			// color = color * color * color;
			// bitmap.setPixel(x, y, 0, color, 0);

			if (iterations != MandelBrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i < iterations; ++i) {
					hue += ((double)histogram[i]) / sum;
				}

				green = pow(255, hue);
			}

			bitmap.setPixel(x, y, red, green, blue);
		}
	}

	bitmap.write("test_3.bmp");

	cout << "Image created." << endl;
	return 0;
}
