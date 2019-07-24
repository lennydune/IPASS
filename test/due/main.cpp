#include "hwlib.hpp"
#include "fft.hpp"
#include <cmath>

namespace ht = hwlib::target;

/// \brief float Remap()
/// 	   remaps given value V on scale A to scale B
/** With the mathematical function below this function changes a floating-point value from one scale to another.

	    newValue = scale_B_low + (scale_B_high - scale_B_low) * ((Value - scale_A_low) / (scale_A_high - scale_A_low)).
	In case `scale_A_high - scale_A_low` equals to 0 then the original value will be returned to negate 0-division errors.*/

float remap(float value, float low1, float high1, float low2, float high2) {
	if ((high1 - low1) != 0) {
		// maths
		return low2 + (high2 - low2) * ((value - low1) / (high1 - low1));
	}
	else {
		// 0-division error; return og value
		return value;
	}
}

int main(void) {
	// setup the audio input
	auto input = ht::pin_adc(ht::ad_pins::a0); // a8 voor final; a0 voor testen
	auto led_sharp = ht::pin_out(ht::pins::d2);
	auto led_flat  = ht::pin_out(ht::pins::d3);


	// loop forever
	while(1) {
		// prepare an array with data - 128 samples or 2^7
		// make sure to set fft::SAMPLE_SIZE to the same value
		CArray data {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

		// insert values
		for (Complex &i : data) {
			// input.read() has a built-in latency, this is why I don't get duplicate data
			i = input.read();
		}

		// perform the transformation on the data
		fft(data);

		// tuner
		Complex avg = {0,0};
		for (size_t i = 1; i < data.size(); i++) {
			avg += data[i];
		}
		avg /= data.size();

		size_t index_max_diff = 0;
		for (size_t i = 1; i < data.size(); i++) {
			if (abs(data[i].real()) > data[index_max_diff].real()) {
				index_max_diff = i;
			}
		}

		hwlib::wait_ms(10);
		int f = 440;	// a nice A
		hwlib::cout << (int)remap(f, 0, 5000, 0, 128) << " - ";
		hwlib::cout << index_max_diff << "\n";

		bool sharp = false;
		bool flat  = false;
		double offset = 2;

		if (index_max_diff > remap(f, 0, 10'000, 0, 128) + offset) {
			sharp = true;
		}
		else if (index_max_diff < remap(f, 0, 10'000, 0, 128) - offset) {
			flat = true;
		}
		else if ((index_max_diff <= (int)remap(f, 0, 10'000, 0, 128) + offset) || (index_max_diff >= (int)remap(f, 0, 10'000, 0, 128) - offset)) {
			// both sharp and flat are true to indicate a correct tone
			sharp = true;
			flat = true;
		}
		else {	// off the scales
			sharp = false;
			flat = false;
		}

		led_sharp.write(sharp);
		led_flat.write(flat);

		// Complex avg, max_diff = {0,0};
		// unsigned int tone = 440;	// a nice A
		// bool flat, sharp = false;
		
		// led_sharp.write(0);
		// led_flat.write(0);

		// for (unsigned int i = 0; i < data.size(); i++) {
		// 	while (i < data.size()/2) {
		// 		avg += data[i];
		// 	}
		// 	avg /= (data.size()/2);
		// 	if (data[i/2].real() > max_diff.real()) {
		// 		max_diff = data[i/2];
		// 	}
		// }

		// unsigned int frequency = remap(max_diff.real(), -10'000, 10'000, 20, 10'000);
		// if (frequency > tone) {
		// 	sharp = true;
		// }
		// if (frequency < tone) {
		// 	flat = true;
		// }
		// if (sharp) {
		// 	led_sharp.write(1);
		// }
		// if (flat) {
		// 	led_flat.write(1);
		// }
	}
}