/*
 * Bitmap.h
 *
 *  Created on: May 4, 2023
 *      Author: s.chandra
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>
using namespace std;

namespace fractal {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	unique_ptr<uint8_t[]> m_pPixels{nullptr};
public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	long int getPixelCount();
	bool write(string filename);
	virtual ~Bitmap();
};

} /* namespace fractal */

#endif /* BITMAP_H_ */
