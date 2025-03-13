#include "RightTriangle.h"
#include <iostream>

	RightTriangle::RightTriangle(int a, int b, int c, int A, int B)
		: Triangle(a, b, c, A, B, 90) {
		if (C != 90) {
			throw FigureExceptions("Должен быть пармой угол.");
		}
	}

	void RightTriangle::print_info() const {
		std::cout << "Right triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}