#pragma once
#include "Triangle.h"
namespace FiguresLibrary
{
	class FIGURESLIBRARY_API IsoscelesTriangle : public Triangle {
	public:
		IsoscelesTriangle(int a, int b, int A, int B);

		void print_info() const override;
	};
}