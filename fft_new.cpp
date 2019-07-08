#include "fft_new.hpp"

/// \brief CArray slice()
///		   Selects every N-th value from a CArray between start and end indexes
/**	Selects every N-th value from a CArray between start and end indexes.*/
CArray slice(CArray &arr, const unsigned int &start, const unsigned int &end, const unsigned int &step) {
	CArray carr;
	for (unsigned int i = start; i < end; i+=step) {
		carr.push_back(arr[i]);
	}
	return carr;
}

// Code snippet derived from Rosetta Code
// Changes have been made to accommodate for hwlib's lack of implementations (in some regards)

/// \brief void fft()
///		   The function which implements the Fast Fourier Transform
/** By applying a Fourier Transformation we can split the audio spectrum into frequency bands.
	Those bands can then be displayed on a screen as bars (example).*/
void fft(CArray &arr) {
	size_t N = index(powers, SAMPLE_SIZE);
	if (N <= 1) return;

	// std::slice replaced with own function -- functionality roughly equal
	// new function implemented in fft_new.cpp
	CArray even = slice(arr, 0, N/2, 2);
	CArray  odd = slice(arr, 1, N/2, 2);

	fft(even);
	fft( odd);

	for (size_t i = 0; i < N/2; i++) {
		// std::polar replaced with own function -- functionality the same
		// new function implemented in complex.cpp
		complex t = polar(1.0, -2 * PI * i / N) * odd[i];
		arr[i] = even[i] + t;
		arr[i+N/2] = even[i] - t;
	}
}
