/*
 * Bitmap.cpp
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace rz;

namespace rz {

Bitmap::Bitmap(int width, int height) :
		_width(width), _height(height), _pixels(
				new uint8_t[width * height * 3] { }) {
	// TODO Auto-generated constructor stub

}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	int fileHeaderSize = sizeof(BitmapFileHeader);
	int infoHeaderSize = sizeof(BitmapInfoHeader);

	fileHeader.filesize = fileHeaderSize + infoHeaderSize
			+ _width * _height * 3;
	fileHeader.dataOffset = fileHeaderSize + infoHeaderSize;

	infoHeader.width = _width;
	infoHeader.height = _height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if (!file) {
		return false;
	}

	file.write((char*) &fileHeader, sizeof(fileHeader));
	file.write((char*) &infoHeader, sizeof(infoHeader));
	file.write((char*) _pixels.get(), _width * _height * 3);

	file.close();

	if (!file) {
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pixel = _pixels.get();

	pixel += (y * 3) * _width + (x * 3);

	pixel[0] = blue;
	pixel[1] = green;
	pixel[2] = red;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace rz */
