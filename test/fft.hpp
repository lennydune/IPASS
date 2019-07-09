#include <complex>
#include <valarray>

/// PI - 3.14... the well known irrational number
const double PI = 3.141592653589793238463;

								/*0, 1, 2, 3,  4,  5,  6,   7,   8,   9,   10*/
const std::array<int, 11> powers {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
const size_t SAMPLE_SIZE = powers[3];

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray &a, size_t N);
void fft(CArray &a);

void reorder(CArray &a, const unsigned int &start, const unsigned int &size, const unsigned int &step);