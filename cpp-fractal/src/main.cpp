//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace rz;

int main() {
	Bitmap bitmap(1280, 720);

	bitmap.write("test.bmp");
	cout << "Finished" << endl; // prints !!!Hello World!!!
	return 0;
}
