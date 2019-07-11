#include <hwlib.hpp>
#include <iostream>
#include "fft.hpp"

/*
Potentiele testcase:
	Stemapparaat, twee leds, een voor te hoog de ander te laag, op basis van de piek die fft detecteert
*/

namespace ht = hwlib::target;

float remap(float value, float low1, float high1, float low2, float high2) {
	if ((high1 - low1) != 0) {
		return low2 + (high2 - low2) * ((value - low1) / (high1 - low1));
	}
	else {
		return value;
	}
}

int main(void) {
// FFT Test
	std::cout << std::endl
			  << "======FFT======\n";
	CArray data {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};

	std::cout << "Input:\n"
			  << "> ";
	for (Complex i : data) {
		std::cout << i;
	}

	fft(data);

	std::cout << "\n"
			  << "Expected output:\n"
			  << "> (4,0)(1,-2.41421)(0,0)(1,-0.414214)(0,0)(1,0.414214)(0,0)(1,2.41421)\n"

			  << "Actual output:\n"
			  << "> ";
	
	for (Complex i : data) {
		std::cout << i;
	}

	std::cout << "\n\n";

// Remap Test
	std::cout << "=====Remap=====\n";
	int a = 5;
	double b = 5.0;

	std::cout << "Input:\n"
			  << "> int    a = " << a << "\n"
			  << "> double b = " << b << "\n"
			  << "> remap(a, 0, 100, 0, 1)\n"
			  << "> remap(b, 0, 10, -5, 5)\n"

			  << "Expected output:\n"
			  << "> a: 0.05\n"
			  << "> b: 0\n"

			  << "Actual output:\n"
			  << "> a: " << remap(a, 0, 100,  0, 1) << "\n"
			  << "> b: " << remap(b, 0, 10,  -5, 5) << "\n";

	std::cout << "\n";

// Reorder Test
	std::cout << "====Reorder====\n";
	CArray c {0,1,2,3,4,5,6,7};

	std::cout << "Input:\n"
			  << "> c: ";
	for (Complex i : c) {
		std::cout << i;
	}

	std::cout << "\n"
			  << "> reorder(c, 0, 4, 2)\n"

			  << "Expected output:\n"
			  << "> c: (0,0)(2,0)(4,0)(6,0)(1,0)(5,0)(3,0)(7,0)\n"

			  << "Actual output:\n"
			  << "> c: ";
	reorder(c, 0, 4, 2);
	for (Complex i : c) {
		std::cout << i;
	}
	std::cout << "\n\n";
}