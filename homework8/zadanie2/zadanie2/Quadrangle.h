#pragma once
#include "Figure.h"
#include "FigureExceptions.h"

class Quadrangle : public Figure {
protected:
	int a, b, c, d;		// Стороны четырехугольника
	int A, B, C, D;		// Углы четырехугольника
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

	void print_info() const override;

};