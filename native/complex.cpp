#include "complex.hpp"
#include <iostream>
complex operator+(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x += rhs;
	return x;
}

complex operator-(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x -= rhs;
	return x;
}

complex operator*(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x *= rhs;
	return x;
}

complex polar(const double &rho, const double &theta) {
	std::cout << "1\n";
	double ct = cos(theta);
	std::cout << "2\n";
	double st = sin(theta);
	std::cout << "3\n";
	ct *= rho;
	std::cout << "4\n";
	st *= rho;
	std::cout << "5\n";
	complex i (ct, st);
	std::cout << "6\n";
	return i;
}
