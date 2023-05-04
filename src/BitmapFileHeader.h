/*
 * bitmap_file_header.h
 *
 *  Created on: May 4, 2023
 *      Author: s.chandra
 */

#ifndef BITMAP_FILE_HEADER_H_
#define BITMAP_FILE_HEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace fractal {

	struct BitmapFileHeader {
		char header[2]{'B', 'M'};
		int32_t fileSize;
		int32_t reserved{0};
		int32_t dataOffset;
	};

} /* namespace fractal */

#endif /* BITMAP_FILE_HEADER_H_ */
