#pragma once
#include "Quadrangle.h"
namespace FiguresLibrary
{
	class FIGURESLIBRARY_API Rhombus : public Quadrangle {
	public:
		Rhombus(int a, int A, int B);

		void print_info() const override;
	};
}