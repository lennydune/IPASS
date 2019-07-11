#include "hwlib.hpp"
#include "fft.hpp"

namespace ht = hwlib::target;

/// \brief float Remap()
/// 	   remaps given value V on scale A to scale B
/** With the mathematical function below this function changes a floating-point value from one scale to another
	`newValue = scale_B_low + (scale_B_high - scale_B_low) * ((Value - scale_A_low) / (scale_A_high - scale_A_low))`
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
	// setup the display with i2c
	auto scl = ht::pin_oc(ht::pins::scl);
	auto sda = ht::pin_oc(ht::pins::sda);
	auto i2c = hwlib::i2c_bus_bit_banged_scl_sda(scl,sda);
	auto display = hwlib::glcd_oled(i2c, 0x3c);

	// setup the audio input
	auto input = ht::pin_adc(ht::ad_pins::a8);

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

		// clear display before displaying stuff
		display.clear();

		// iterate over every pixel that has to be written to (turned white/on)
		for (int x = 0; x < display.size.x; x++) {
			// also remap the data to usable values
			for (int y = 0; y < (int)remap(data[x].real(), -5000, 5000, 0, display.size.y); y++) {
				display.write(hwlib::xy(x,display.size.y - y));
			}
		}

		// flush the display and do it all again
		display.flush();
	}
}