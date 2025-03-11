#pragma once
#include "Quadrangle.h"

class Square : public Quadrangle {
public:
	Square(int a);

	void print_info() const override;
};