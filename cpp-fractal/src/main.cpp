//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace rz;

int main() {
	int const WIDTH = 1280, HEIGHT = 720;
	Bitmap bitmap(WIDTH, HEIGHT);

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			double xFractal = (x-WIDTH/2-200) * 2.0/HEIGHT;
			double yFractal = (y-HEIGHT/2) * 2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			uint8_t color = (uint8_t) (256*(double) iterations/Mandelbrot::MAX_ITERATIONS);
			color = color*color;

			bitmap.setPixel(x, y, 0, color, color);
		}
	}

	bitmap.write("test.bmp");

	cout << "Finished" << endl; // prints !!!Hello World!!!
	return 0;
}
