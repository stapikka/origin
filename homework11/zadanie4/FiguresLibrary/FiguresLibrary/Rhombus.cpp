#include <iostream>
#include "Rhombus.h"

namespace FiguresLibrary
{
	Rhombus::Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {}

	void Rhombus::print_info() const {
		std::cout << "Rhombus:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
}