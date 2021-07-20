/*
 * Mandelbrot.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "Fractal.h"

namespace rz {

class Mandelbrot: public virtual Fractal {
public:
	int getIterations(double x, double y, int maxIterations);
};

} /* namespace rz */

#endif /* MANDELBROT_H_ */
