/*
 * ZoomList.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace rz {

class ZoomList {
private:
	double _xCenter { 0 }, _yCenter { 0 };
	double _scale { 1.0 };
	int _width { 0 }, _height { 0 };
	vector<Zoom> zooms;

public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
	pair<double, double> doZoom(int x, int y);
};

} /* namespace rz */

#endif /* ZOOMLIST_H_ */
