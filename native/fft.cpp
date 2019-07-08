#include "fft.hpp"

CArray slice(CArray &arr, const unsigned int &start, const unsigned int &end, const unsigned int &step) {
	CArray carr;
	for (unsigned int i = start; i < end; i+=step) {
		carr.push_back(arr[i]);
	}
	return carr;
}

void fft(CArray &arr) {
	const size_t N = arr.size();
	if (N <= 1) return;

	CArray even = slice(arr, 0, N/2, 2);
	CArray  odd = slice(arr, 1, N/2, 2);

	fft(even);
	fft( odd);

	for (size_t i = 0; i < N/2; i++) {
		complex t = polar(1.0, -2 * PI * i / N) * odd[i];
		arr[i] = even[i] + t;
		arr[i+N/2] = even[i] - t;
	}
}
