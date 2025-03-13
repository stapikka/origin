#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"
#include "FigureExceptions.h"

void print_info(Figure* F) {
	F->print_info();
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	try {
		RightTriangle rt(10, 20, 30, 60, 30);
		Rhombus r(20, 90, 90);
		rt.print_info();
		r.print_info();
	}
	catch (const FigureExceptions& er) {
		std::cout << er.what() << std::endl;
	}

	return 0;
}