/*
 * ZoomList.cpp
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#include "ZoomList.h"

namespace rz {

ZoomList::ZoomList(int width, int height) :
		_width(width), _height(height) {
	// TODO Auto-generated constructor stub

}

void ZoomList::add(const Zoom &zoom) {
	zooms.push_back(zoom);

	_xCenter += (zoom.x - _width / 2) * _scale;
	_yCenter += -(zoom.y - _height / 2) * _scale;

	_scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x, int y) {
	double xFractal = (x - _width / 2) * _scale + _xCenter;
	double yFractal = (y - _height / 2) * _scale + _yCenter;

	return pair<double, double>(xFractal, yFractal);
}

} /* namespace rz */
