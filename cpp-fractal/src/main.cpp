//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <utility>
#include <math.h>
#include "FractalCreator.h"
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Julia.h"
#include "Fractal.h"

using namespace std;
using namespace rz;

int main() {

	Julia julia(-0.8, 0.156);
//	Mandelbrot mandelbrot;
	FractalCreator fractalCreator(1280, 720, 1000, julia);

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(255, 99, 71));
	fractalCreator.addRange(0.08, RGB(255, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

//	fractalCreator.addZoom(Zoom(400, 300, 0.5));
//	fractalCreator.addZoom(Zoom(188, 268, 0.01));
//	fractalCreator.addZoom(Zoom(312, 304, 0.1));

	fractalCreator.run("test.bmp");

	cout << "Finished" << endl; // prints !!!Hello World!!!
	return 0;
}
