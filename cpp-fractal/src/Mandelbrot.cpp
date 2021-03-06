/*
 * Mandelbrot.cpp
 *
 *  Created on: Jul 19, 2021
 *      Author: Raymon
 */

#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace rz {

int Mandelbrot::getIterations(double x, double y, int maxIterations) {
	complex<double> z = 0;
	complex<double> c(x, y);

	int iterations = 0;

	while (iterations < maxIterations) {
		z = z * z + c;

		if (abs(z) > 2) {
			break;
		}

		iterations++;
	}

	return iterations;
}

} /* namespace rz */
