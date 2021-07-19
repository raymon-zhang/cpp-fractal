/*
 * BitmapFileHeader.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(push, 2)

namespace rz {

struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t filesize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

}

#endif /* BITMAPFILEHEADER_H_ */
