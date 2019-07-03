#include <hwlib.hpp>
#include <unistd.h>
#include "fft.hpp"

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
	ht::window w(hwlib::xy(128, 64));
	srand(time(0));
	
	for(;;) {
		Complex test[] = {(double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096),
					 (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096), (double)(rand()%4096)};

		CArray data(test, SAMPLE_SIZE);

		fft(data);

		w.clear();

		for (unsigned int x = 0; x < w.size.x; x++) {
			for (int y = 0; y < remap(data[x].real(), -30000, 30000, 0, w.size.y); y++) {
				w.write(hwlib::xy(x,w.size.y - y));
			}
		}
		usleep(100*1000);
		w.flush();
	}
	return 0;
}