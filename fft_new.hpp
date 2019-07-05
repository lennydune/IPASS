#include "complex.hpp"

/// PI - 3.14... the well known irrational number
const double PI = 3.141592653589793238463;

typedef std::array<complex, 128> CArray;

void fft(CArray &a);