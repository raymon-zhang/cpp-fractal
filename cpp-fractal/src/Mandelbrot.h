/*
 * Mandelbrot.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace rz {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;
public:
	static int getIterations(double x, double y);
};

} /* namespace rz */

#endif /* MANDELBROT_H_ */
