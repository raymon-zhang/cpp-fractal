/*
 * Julia.h
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#ifndef JULIA_H_
#define JULIA_H_

#include "Fractal.h"

namespace rz {

class Julia: public Fractal {
private:
	double _cX { 0 }, _cY { 0 };
public:
	Julia(double x, double y);
	int getIterations(double x, double y, int maxIterations);
};

} /* namespace rz */

#endif /* JULIA_H_ */
