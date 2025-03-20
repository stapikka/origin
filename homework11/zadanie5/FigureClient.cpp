#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"

using namespace FiguresLibrary;

void print_info(Figure* F) {
	F->print_info();
}

int main() {

	Triangle t(10, 20, 30, 30, 30, 30);
	print_info(&t);

	return 0;
}