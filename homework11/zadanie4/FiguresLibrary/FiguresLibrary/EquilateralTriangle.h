#pragma once
#include "Triangle.h"
namespace FiguresLibrary
{
	class FIGURESLIBRARY_API EquilateralTriangle : public Triangle {
	public:
		EquilateralTriangle(int a);

		void print_info() const override;
	};
}