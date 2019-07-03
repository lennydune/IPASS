#include <complex>
#include <valarray>

const double PI = 3.141592653589793238463;
const size_t SAMPLE_SIZE = 128;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray &a);