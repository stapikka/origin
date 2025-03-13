#include "Square.h"

	Square::Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
		if (a != b || b != c || c != d || A != B || B != C || C != D || A != 60) {
			throw FigureExceptions("все стороны должны быть равны, все углы должны быть равны 90");
		}
	}

	void Square::print_info() const {
		std::cout << "Square:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
