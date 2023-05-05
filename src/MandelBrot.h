/*
 * MandelBrot.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractal {

class MandelBrot {
public:
	static const int MAX_ITERATIONS = 1100;
public:
	MandelBrot();
	virtual ~MandelBrot();

	static int getIterations(double x, double y);
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
