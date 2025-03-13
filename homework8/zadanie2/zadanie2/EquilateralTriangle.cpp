#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int a)
	: Triangle(a, a, a, 60, 60, 60) {
	if (a != b || b != c || A != B || B != C || A != 60) {
		throw FigureExceptions("¬се стороны должны быть равны и углы по 60.");
	}
}

	void EquilateralTriangle::print_info() const {
		std::cout << "Equilateral triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
