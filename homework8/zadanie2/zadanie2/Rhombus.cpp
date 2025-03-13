#include <iostream>
#include "Rhombus.h"


Rhombus::Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {
	if (a != b || b != c || c != d || A != C || B != D) {
		throw FigureExceptions("все стороны должны быть равны, а углы A,C и B,D попарно равны.");
	}
}

	void Rhombus::print_info() const {
		std::cout << "Rhombus:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}