#include <iostream>
#include "EquilateralTriangle.h"
namespace FiguresLibrary
{
	EquilateralTriangle::EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

	void EquilateralTriangle::print_info() const {
		std::cout << "Equilateral triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
}
