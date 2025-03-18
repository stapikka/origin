#include <iostream>
#include "Quadrangle.h"

	Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

	void Quadrangle::print_info() const {
		std::cout << "Quadrangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
