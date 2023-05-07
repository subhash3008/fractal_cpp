/*
 * FractalCreator.cpp
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#include <iostream>
#include <assert.h>
#include "FractalCreator.h"

using namespace std;

namespace fractal {

void FractalCreator::run(string name) {
	calculateIterations();
	calcTotalIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap(name);
}

void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
	m_ranges.push_back(rangeEnd * MandelBrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}
	m_bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const {
	int range = 0;
	for (int i = 1; i < m_ranges.size(); ++i) {
		range = i;
		if (m_ranges[i] > iterations) {
			break;
		}
	}

	range--;

	assert(range > -1);
	assert(range < m_ranges.size());

	return range;
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

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

void FractalCreator::calculateRangeTotals() {
	int rangeIndex = 0;
	for (int i = 0; i < MandelBrot::MAX_ITERATIONS; ++i) {
		int pixels = m_histogram[i];

		if (i >= m_ranges[rangeIndex + 1])
		{
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
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
			int iterations = m_fractal[y * m_width + x];
			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range + 1];
			RGB colorDiff = endColor - startColor;


			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;


			// for test.bmp
			// uint8_t color = (uint8_t)(256 *
			//		((double)(iterations) / MandelBrot::MAX_ITERATIONS));
			// color = color * color * color;
			// bitmap.setPixel(x, y, 0, color, 0);

			if (iterations != MandelBrot::MAX_ITERATIONS) {
				int totalPixels = 0;

				for (int i = rangeStart; i < iterations; ++i) {
					totalPixels += m_histogram[i];
				}

				// till test_3
				// green = pow(255, hue);
				// green = hue * 255;

				red = startColor.m_r +
						colorDiff.m_r * ((double)totalPixels / rangeTotal);
				green = startColor.m_g +
						colorDiff.m_g * ((double)totalPixels / rangeTotal);
				blue = startColor.m_b +
						colorDiff.m_b * ((double)totalPixels / rangeTotal);
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::writeBitmap(string filename) {
	m_bitmap.write(filename);
}


FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
}

} /* namespace fractal */
