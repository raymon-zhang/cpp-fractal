/*
 * RGB.h
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#ifndef RGB_H_
#define RGB_H_

namespace rz {

struct RGB {
	double r, g, b;
	RGB(double r, double g, double b);
};

RGB operator-(const RGB &first, const RGB &second);

} /* namespace rz */

#endif /* RGB_H_ */
