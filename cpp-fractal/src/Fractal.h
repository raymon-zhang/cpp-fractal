/*
 * Fractal.h
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#ifndef FRACTAL_H_
#define FRACTAL_H_

namespace rz {

class Fractal {
public:
	virtual int getIterations(double x, double y, int maxIterations) = 0;
	virtual ~Fractal() {
	}
	;
};

} /* namespace rz */

#endif /* FRACTAL_H_ */
