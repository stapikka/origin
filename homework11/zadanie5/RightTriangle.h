#pragma once
#include "Triangle.h"
namespace FiguresLibrary
{
	class RightTriangle :public Triangle {
	public:
		FIGURESLIBRARY_API RightTriangle(int a, int b, int c, int A, int B);

		void print_info() const override;
	};
}
