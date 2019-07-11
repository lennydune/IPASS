#include <complex>
#include <array>

/// PI - 3.14... the well known irrational number
const double PI = 3.141592653589793238463;

					/*0, 1, 2, 3,  4,  5,  6,   7,   8,   9,   10*/
const int powers[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
const size_t SAMPLE_SIZE = powers[7];


typedef std::complex<double> Complex;
typedef std::array<Complex, SAMPLE_SIZE> CArray;

/// \brief void fft(CArray, size_t)
///		   Implements the Fast Fourier Transform
/** Fast Fourier Transform is an algorithm to retrieve the present functions and their amplitudes from a given signal.*/
void fft(CArray &arr, size_t N);

/// \brief void fft(CArray)
///		   This is the function that calls fft(CArray, size_t)
/** This exists to make it easier to call fft().
	All it does is call the fft method below*/
void fft(CArray &a);

/// \brief void reorder()
///		   Selects every Nth value and places it in front of the array
/** Iterates over an array for the given size from the given start point
	Then it swaps those values with those at front.
	The functionality is similar to what std::slice does and it is based on it.
	The only difference between reorder and slice is that reorder uses the original array and doesn't throw it away.*/
void reorder(CArray &a, const unsigned int &start, const unsigned int &size, const unsigned int &step);