#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "MandelBrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace fractal;


int main() {
	int height = 600;
	FractalCreator fractalCreator(800, 600);

	fractalCreator.addZoom(Zoom(101, height - 284, .1));
	fractalCreator.addZoom(Zoom(679, height - 379, .05));
	fractalCreator.addZoom(Zoom(420, height - 326, .05));

	fractalCreator.calculateIterations();
	fractalCreator.calcTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("test_3.bmp");

	cout << "Image created." << endl;
	return 0;
}
