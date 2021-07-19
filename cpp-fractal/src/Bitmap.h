/*
 * Bitmap.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>
using namespace std;

namespace rz {

class Bitmap {
private:
	int _width { 0 }, _height { 0 };
	unique_ptr<uint8_t[]> _pixels { nullptr };

public:
	Bitmap(int width, int height);
	bool write(string filename);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	virtual ~Bitmap();
};

} /* namespace rz */

#endif /* BITMAP_H_ */
