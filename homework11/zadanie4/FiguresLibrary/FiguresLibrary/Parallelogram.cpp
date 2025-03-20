#include <iostream>
#include "Parallelogram.h"

namespace FiguresLibrary
{
	Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

	void Parallelogram::print_info() const {
		std::cout << "Parallelogram:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
}
