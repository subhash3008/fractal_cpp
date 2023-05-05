/*
 * FractalCreator.cpp
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#include "FractalCreator.h"

namespace fractal {

FractalCreator::FractalCreator(int width, int height):
	m_width(width),
	m_height(height),
	m_histogram(new int[MandelBrot::MAX_ITERATIONS]{0}),
	m_fractal(new int[width * height]{0}),
	m_bitmap(width, height),
	m_zoomList(width, height){
	// TODO Auto-generated constructor stub
	this->addZoom(Zoom(m_width / 2, m_height / 2, (4.0 / m_width)));
}

void FractalCreator::calculateIterations() {
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			// bitmap.setPixel(x, y, 0xFF, 0x0, 0x0);
			pair<double, double> coords = m_zoomList.doZoom(x, y);


			int iterations = MandelBrot::getIterations(
					coords.first,
					coords.second);

			m_fractal[y*m_width + x] = iterations;

			if (iterations != MandelBrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;;
			}
		}
	}
}

void FractalCreator::calcTotalIterations() {
	for (int i = 0; i < MandelBrot::MAX_ITERATIONS; ++i) {
		m_totalIterations += m_histogram[i];
	}
}

void FractalCreator::drawFractal() {

	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = m_fractal[y * m_width + x];

			// for test.bmp
			// uint8_t color = (uint8_t)(256 *
			//		((double)(iterations) / MandelBrot::MAX_ITERATIONS));
			// color = color * color * color;
			// bitmap.setPixel(x, y, 0, color, 0);

			if (iterations != MandelBrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i < iterations; ++i) {
					hue += ((double)m_histogram[i]) / m_totalIterations;
				}

				// green = pow(255, hue);
				green = hue * 255;
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string filename) {
	m_bitmap.write(filename);
}


FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
}

} /* namespace fractal */
