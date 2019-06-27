#include "hwlib.hpp"

namespace ht = hwlib::target;

// remaps given value between low1 and high1 to a value between low2 and high2
float remap(float value, float low1, float high1, float low2, float high2) {
	if ((high1 - low1) != 0) {
		return low2 + (high2 - low2) * ((value - low1) / (high1 - low1));
	}
	else {
		return value;
	}
}

int main(void) {
	auto scl = ht::pin_oc(ht::pins::scl);
	auto sda = ht::pin_oc(ht::pins::sda);
	auto i2c = hwlib::i2c_bus_bit_banged_scl_sda(scl,sda);
	auto display = hwlib::glcd_oled(i2c,0x3c);

	display.clear();
	
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < remap(i, 0, 128, 0, 64); j++) {
			display.write(hwlib::xy(i, j));
		}
	}

	display.flush();
}