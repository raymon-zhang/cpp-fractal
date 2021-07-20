/*
 * Julia.cpp
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#include <complex>
#include "Julia.h"

using namespace std;

namespace rz {

Julia::Julia(double x, double y) :
		_cX(x), _cY(y) {
}

int Julia::getIterations(double x, double y, int maxIterations) {
	complex<double> z(x, y);
	complex<double> c(_cX, _cY);

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
