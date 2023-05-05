/*
 * FractalCreator.h
 *
 *  Created on: May 5, 2023
 *      Author: s.chandra
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>

using namespace std;

namespace fractal {

class FractalCreator {
public:
	FractalCreator();
	virtual ~FractalCreator();

	void calculateIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(string filename);
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
