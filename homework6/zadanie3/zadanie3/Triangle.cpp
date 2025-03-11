#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
	: a(a), b(b), c(c), A(A), B(B), C(C) {}

void Triangle::print_info() const {
	std::cout << "Triangle:\n"
		<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
		<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
}