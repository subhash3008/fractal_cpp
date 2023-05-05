/*
 * Zoom.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace fractal {

struct Zoom {
	int x{0};
	int y{0};
	double scale{1.0};


	Zoom(int x, int y, double scale): x(x), y(y), scale(scale){};
};

} /* namespace fractal */

#endif /* ZOOM_H_ */
