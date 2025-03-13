#include "IsoscelesTriangle.h"


IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) 
	: Triangle(a, b, a, A, B, A) {
	if (a != c || A != C) {
		throw FigureExceptions("Должны быть две одинаковые стороны и два одинаковых угла.");
	}
}

	void IsoscelesTriangle::print_info() const {
		std::cout << "Isosceles triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
