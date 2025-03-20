#pragma once
#include "Quadrangle.h"

namespace FiguresLibrary
{
	class FIGURESLIBRARY_API Square : public Quadrangle {
	public:
		Square(int a);

		void print_info() const override;
	};
}