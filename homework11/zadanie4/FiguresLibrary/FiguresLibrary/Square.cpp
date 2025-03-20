#include <iostream>
#include "Square.h"
namespace FiguresLibrary
{
	Square::Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {}

	void Square::print_info() const {
		std::cout << "Square:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
}
