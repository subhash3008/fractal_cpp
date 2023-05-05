/*
 * MandelBrot.cpp
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#include <complex>
#include "MandelBrot.h"

using namespace std;

namespace fractal {

MandelBrot::MandelBrot() {
	// TODO Auto-generated constructor stub

}

MandelBrot::~MandelBrot() {
	// TODO Auto-generated destructor stub
}

int MandelBrot::getIterations(double x, double y) {
	complex<double> z = 0;
	complex<double> c(x, y);
	int iterations = 0;

	while (iterations < MAX_ITERATIONS) {
		z = z*z + c;

		if (abs(z) > 2) {
			break;
		}

		iterations++;
	}

	return iterations;

}

} /* namespace fractal */
