/*
 * FractalCreator.cpp
 *
 *  Created on: Jul 20, 2021
 *      Author: Raymon
 */

#include "FractalCreator.h"

namespace rz {

FractalCreator::FractalCreator(int width, int height, int maxIterations,
		Fractal &fractalType) :
		_width(width), _height(height), _maxIterations(maxIterations), _fractalType(
				fractalType), _histogram(new int[_maxIterations] { }), _fractal(
				new int[_width * _height] { }), _bitmap(_width, _height), _zoomList(
				_width, _height) {

	_zoomList.add(Zoom(_width / 2, _height / 2, 4.0 / _width));
}

void FractalCreator::calculateIterations() {
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			pair<double, double> coords = _zoomList.doZoom(x, y);

			int iterations = _fractalType.getIterations(coords.first,
					coords.second, _maxIterations);

			_fractal[y * _width + x] = iterations;

			if (iterations != _maxIterations) {
				_histogram[iterations]++;
			}

		}
	}
}

void FractalCreator::calculateRangeTotals() {
	int rangeIndex = 0;

	for (int i = 0; i < _maxIterations; i++) {
		int pixels = _histogram[i];

		if (i >= _ranges[rangeIndex + 1]) {
			rangeIndex++;
		}

		_rangeTotals[rangeIndex] += pixels;
	}
}

int FractalCreator::getRange(int iterations) const {
	int range = 0;

	for (unsigned int i = 1; i < _ranges.size(); i++) {
		range = i;

		if (_ranges[i] > iterations) {
			break;
		}
	}

	range--;

	return range;
}

void FractalCreator::drawFractal() {
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			int iterations = _fractal[y * _width + x];

			int range = getRange(iterations);
			int rangeTotal = _rangeTotals[range];
			int rangeStart = _ranges[range];

			RGB &startColor = _colors[range];
			RGB &endColor = _colors[range + 1];
			RGB colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != _maxIterations) {

				int totalPixels = 0;

				for (int i = rangeStart; i <= iterations; i++) {
					totalPixels += _histogram[i];
				}

				red = startColor.r
						+ colorDiff.r * (double) totalPixels / rangeTotal;
				green = startColor.g
						+ colorDiff.g * (double) totalPixels / rangeTotal;
				blue = startColor.b
						+ colorDiff.b * (double) totalPixels / rangeTotal;
			}

			_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::writeBitmap(string name) {
	_bitmap.write(name);
}

void FractalCreator::addZoom(const Zoom &zoom) {
	_zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
	_ranges.push_back(rangeEnd * _maxIterations);
	_colors.push_back(rgb);

	if (_gotFirstRange) {
		_rangeTotals.push_back(0);
	}

	_gotFirstRange = true;
}

void FractalCreator::run(string name) {
	calculateIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap(name);
}

} /* namespace rz */
