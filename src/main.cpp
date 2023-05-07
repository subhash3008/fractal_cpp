#include <iostream>
#include "RGB.h"
#include "FractalCreator.h"
#include "Zoom.h"

using namespace std;
using namespace fractal;


int main() {
	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(.3, RGB(128, 128, 128));
	fractalCreator.addRange(.5, RGB(0, 128, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 0));

	fractalCreator.addZoom(Zoom(101, 284, .1));
	fractalCreator.addZoom(Zoom(679, 379, .1));
	fractalCreator.run("test_4.bmp");


	cout << "Image created." << endl;
	return 0;
}
