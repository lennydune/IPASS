#include "fft2.hpp"

void reorder(CArray &arr, const unsigned int &start, const unsigned int &end, const unsigned int &step) {
	for (unsigned int i = start; i < end/2; i++) {
		std::swap(arr[i], arr[i+step]);
	}
}

template<class Iterator>
void fft(Iterator &arr, size_t N) {
	if (N <= 1) return;

	CArray a1 = arr;
	CArray a2 = arr;

	reorder(a1, 0, N/2, 2);
	reorder(a2, 1, N/2, 2);

	fft(a1, N/2);
	fft(a2, N/2);

	for (unsigned int i = 0; i < N/2; i++) {
		Complex t = std::polar(1.0, -2 * PI * i / N) * a2[i];
		arr[i] = a1[i] + t;
		arr[i+N/2] = a1[i] - t;
	}
}

void fft(CArray &arr) {
	unsigned int N = arr.size();
	if (N <= 1) return;

	CArray a1 = arr;
	CArray a2 = arr;

	reorder(a1, 0, N/2, 2);
	reorder(a2, 1, N/2, 2);

	fft(a1, N/2);
	fft(a2, N/2);

	for (unsigned int i = 0; i < N/2; i++) {
		Complex t = std::polar(1.0, -2 * PI * i / N) * a2[i];
		arr[i] = a1[i] + t;
		arr[i+N/2] = a1[i] - t;
	}
}
