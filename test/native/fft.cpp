#include "fft.hpp"

void fft(CArray &arr) {
	const size_t N = arr.size();
	if (N <= 1) return;

	CArray even = arr[std::slice(0, N/2, 2)];
	CArray  odd = arr[std::slice(1, N/2, 2)];

	fft(even);
	fft( odd);

	for (size_t i = 0; i < N/2; i++) {
		Complex t = std::polar(1.0, -2 * PI * i / N) * odd[i];
		arr[i] = even[i] + t;
		arr[i+N/2] = even[i] - t;
	}
}
