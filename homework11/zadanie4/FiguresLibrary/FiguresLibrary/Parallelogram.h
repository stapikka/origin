#pragma once
#include "Quadrangle.h"
namespace FiguresLibrary
{
	class FIGURESLIBRARY_API Parallelogram : public Quadrangle {
	public:
		Parallelogram(int a, int b, int A, int B);

		void print_info() const override;
	};
}