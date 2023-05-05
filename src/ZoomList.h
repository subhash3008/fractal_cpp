/*
 * ZoomList.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace fractal {

class ZoomList {
private:
	double m_xCenter{0};
	double m_yCenter{0};
	double m_scale{1.0};

	int m_width{0};
	int m_height{0};
	vector<Zoom> m_zooms;

public:
	ZoomList(int width, int height);

	void add(const Zoom &zoom);
	pair<double, double> doZoom(int x, int y);
};

} /* namespace fractal */

#endif /* ZOOMLIST_H_ */
