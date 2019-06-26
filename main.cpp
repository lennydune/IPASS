#include "hwlib.hpp"
#include "fft.hpp"
#include <complex>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

// remaps given value between low1 and high1 to a value between low2 and high2
float remap(float value, float low1, float high1, float low2, float high2) {
	if ((high1 - low1) != 0) {
		return low2 + (high2 - low2) * ((value - low1) / (high1 - low1));
	}
	else {
		std::cout << "Error, remap values invalid\n";
		return 0;
	}
}

int main(void){
	srand((unsigned)time(0));
	hwlib::target::window w(hwlib::xy(128,64), 1);

	for(;;) {
		w.clear();
		Complex test[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		CArray data(test, 128);

		fft(data);

		for (int i = 0; i < 128; i++) {
			hwlib::line l(hwlib::xy(i,0), hwlib::xy(i, (int)remap(data[i].real(), -6000.0, 6000.0, 0.0, 128.0)));
			l.draw(w);
			usleep(500);
		}
		w.flush();
	}
	return 0;
}