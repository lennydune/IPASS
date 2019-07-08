#include "complex.hpp"

complex polar(const double &rho, const double &theta) {
	return complex(rho * cos(theta), rho * sin(theta));
}
