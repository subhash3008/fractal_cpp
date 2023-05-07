/*
 * RGB.cpp
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#include "RGB.h"

namespace fractal {

RGB::RGB(double r, double g, double b):
	m_r(r),
	m_g(g),
	m_b(b) {
	// TODO Auto-generated constructor stub
}

RGB RGB::operator-(const RGB& rgb) {
	return RGB(
			this->m_r - rgb.m_r,
			this->m_g - rgb.m_g,
			this->m_b - rgb.m_b);

}


} /* namespace fractal */
