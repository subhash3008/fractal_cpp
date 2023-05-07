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
#include <vector>
#include "Bitmap.h"
#include "MandelBrot.h"
#include "RGB.h"
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
	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;
	bool m_bGotFirstRange{false};

private:
	void calculateIterations();
	void calcTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(string filename);
	int getRange(int iterations) const;


public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void addRange(double rangeEnd, const RGB& rgb);
	void addZoom(const Zoom& zoom);
	void run(string name);
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
