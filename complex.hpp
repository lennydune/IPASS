#include <cmath>

/// \brief class complex
///		   The class to implement complex numbers
/** The c++-11 implementation of complex numbers doesn't play nice with hwlib.
	Therefore I copied the parts I needed from the c++-11 implementation over here.
	There are still some problems however, something with `operator new()` and `operator delete()` not being defined.*/
class complex {
public:
	/// imag - The imaginary part of a complex number.
	/// Also known as i, the square root of -1
	double imag;

	/// real - The real part of a complex number.
	/// Any non-imaginary number from negative infinity to positive infinity
	double real;

	/// \brief complex constructor
	/** This constructor initializes complex with an imaginary and real part.*/
	complex(const double &r, const double &i = 0):
		imag(i),
		real(r)
		{}

	/// \brief complex operator+=
	///		   Add a complex number into another complex number
	complex& operator+=(const complex &rhs) {
		real += rhs.real;
		imag += rhs.imag;
		return *this;
	}

	/// \brief complex operator-=
	///		   Subtract a complex number into another complex number
	complex& operator-=(const complex &rhs) {
		real -= rhs.real;
		imag -= rhs.imag;
		return *this;
	}

	/// \brief complex operator*=
	///		   Multiply a complex number into another complex number
	complex& operator*=(const complex &rhs) {
		real *= rhs.real;
		imag *= rhs.imag;
		return *this;
	}

	/// \brief complex operator+
	///		   Add a complex number with another complex number
	complex operator+(const complex &rhs) {
		complex x = *this;
		x += rhs;
		return x;
	}

	/// \brief complex operator-
	///		   Subtract a complex number with another complex number
	complex operator-(const complex &rhs) {
		complex x = *this;
		x -= rhs;
		return x;
	}

	/// \brief complex operator*
	///		   Multiply a complex number with another complex number
	complex operator*(const complex &rhs) {
		complex x = *this;
		x *= rhs;
		return x;
	}
};

/// \brief complex polar
///		   Return the polar coordinates for a complex number in euclidean space
/** By multiplying the sine and cosine of theta with rho we get the coordinates.
	These can be used with [remap](@ref remap)*/
complex polar(const double &rho, const double &theta);

class complexArray {
private:
	complex arr[8][128] = {
	// 2^0
		{-1},
	// 2^1
		{-1,-1},
	// 2^2
		{-1,-1,-1,-1},
	// 2^3
		{-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^4
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^5
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^6
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^7
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	};
/*
	std::array<std::array<complex, 128>, 8> arr = {
	// 2^0
		std::array<complex, 128> a = {-1},
	// 2^1
		std::array<complex, 128> b = {-1,-1},
	// 2^2
		std::array<complex, 128> c = {-1,-1,-1,-1},
	// 2^3
		std::array<complex, 128> d = {-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^4
		std::array<complex, 128> e = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^5
		std::array<complex, 128> f = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^6
		std::array<complex, 128> g = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	// 2^7
		std::array<complex, 128> h = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	};
*/
};