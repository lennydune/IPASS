#include "complex.hpp"
#include <vector>

/// PI - 3.14... the well known irrational number
const double PI = 3.141592653589793238463;

/// CArray - an array of complex numbers
typedef std::vector<complex> CArray;

void fft(std::vector<complex> &a);