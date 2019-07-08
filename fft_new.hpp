#include <complex>
#include <array>

/// PI - 3.14... the well known irrational number
const double PI = 3.141592653589793238463;

const size_t MAX_POW = 11;
const std::array<int, MAX_POW> powers {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
const size_t SAMPLE_SIZE = powers[7];

typedef std::complex<double> Complex;
typedef std::array<Complex, SAMPLE_SIZE> CArray;

void fft(CArray &a);

template <class Type>
unsigned int index(std::array<Type, MAX_POW> &arr, Type &val) {
	for (size_t i = 0; i < MAX_POW; i++) {
		if (arr[i] == val) {
			return i;
		}
	}
}