/*
 * FractalCreator.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "MandelBrot.h"
#include "ZoomList.h"

using namespace std;

namespace fractal {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_totalIterations{0};

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIterations();
	void calcTotalIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(string filename);
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
