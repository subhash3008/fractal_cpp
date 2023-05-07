/*
 * RGB.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef RGB_H_
#define RGB_H_

namespace fractal {

struct RGB {
	double m_r;
	double m_g;
	double m_b;

	RGB(double r, double g, double b);
	RGB operator-(const RGB& rgb);
};

} /* namespace fractal */

#endif /* RGB_H_ */
