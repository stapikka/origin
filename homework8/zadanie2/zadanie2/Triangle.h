#pragma once
#include "Figure.h"
#include "FigureExceptions.h"

class Triangle : public Figure {
protected:
	int a, b, c;	// Стороны треугольника
	int A, B, C;	// Углы треугольника
public:
	Triangle(int a, int b, int c, int A, int B, int C);

	void print_info() const override;

};