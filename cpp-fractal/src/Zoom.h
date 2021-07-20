/*
 * Zoom.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace rz {

struct Zoom {
	int x { 0 }, y { 0 };
	double scale { 0.0 };

	Zoom(int x, int y, double scale) :
			x(x), y(y), scale(scale) {
	}
};

} /* namespace rz */

#endif /* ZOOM_H_ */
