#include "complex.hpp"
#include <vector>

const double PI = 3.141592653589793238463;
const size_t SAMPLE_SIZE = 128;

typedef std::vector<complex> CArray;

void fft(CArray &a);