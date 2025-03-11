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

void print_info(Figure* F) {
	F->print_info();
}

int main() {
	Triangle t(10, 20, 30, 30, 30, 30);
	RightTriangle rt(10, 20, 30, 45, 45);
	IsoscelesTriangle it(10, 20, 30, 120);
	EquilateralTriangle et(30);
	Quadrangle q(10, 15, 10, 20, 95, 5, 200, 60);
	Square s(10);
	Parallelogram p(30, 40, 60, 120);
	Rhombus r(50, 60, 120);
	print_info(&t);
	print_info(&rt);
	print_info(&it);
	print_info(&et);
	print_info(&q);
	print_info(&s);
	print_info(&p);
	print_info(&r);

	return 0;
}