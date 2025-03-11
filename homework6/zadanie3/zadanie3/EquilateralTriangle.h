#pragma once
#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a);

	void print_info() const override;
};