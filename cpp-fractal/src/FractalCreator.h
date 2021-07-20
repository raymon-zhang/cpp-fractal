/*
 * FractalCreator.h
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>
#include <vector>
#include <math.h>
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "Fractal.h"

using namespace std;

namespace rz {

class FractalCreator {
private:
	int _width { 0 }, _height { 0 };
	int _maxIterations { 50 };
	Fractal &_fractalType;
	unique_ptr<int[]> _histogram;
	unique_ptr<int[]> _fractal;
	Bitmap _bitmap;
	ZoomList _zoomList;

	vector<int> _ranges;
	vector<RGB> _colors;
	vector<int> _rangeTotals;

	bool _gotFirstRange { false };

private:
	void calculateIterations();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(string name);
	int getRange(int getIterations) const;

public:
	FractalCreator(int width, int height, int maxIterations,
			Fractal &fractalType);

	void run(string name);
	void addZoom(const Zoom &zoom);
	void addRange(double rangeEnd, const RGB &rgb);
};

} /* namespace rz */

#endif /* FRACTALCREATOR_H_ */
