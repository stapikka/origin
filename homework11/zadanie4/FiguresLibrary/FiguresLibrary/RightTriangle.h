#pragma once
#include "Triangle.h"
namespace FiguresLibrary
{
	class FIGURESLIBRARY_API RightTriangle :public Triangle {
	public:
		RightTriangle(int a, int b, int c, int A, int B);

		void print_info() const override;
	};
}
