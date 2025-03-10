#include <iostream>
#include <string>

class Figure {
protected:
	int numOfSides;
	std::string nameOfFigure;
public:
	Figure(int sides = 0, std::string name = "Figure") : numOfSides(sides), nameOfFigure(name) {}
	virtual void print_info() const {
		std::cout << nameOfFigure << std::endl;
		std::cout << "Number of sides: " << numOfSides << std::endl;
		std::cout << (check() ? "Correct!\n" : "Wrong!\n");
	}
	virtual bool check() const {
		if (!(numOfSides == 0)) {
			return false;
		}
		return true;
	}
};

class Triangle : public Figure {
protected:
	int a, b, c;	// Стороны треугольника
	int A, B, C;	// Углы треугольника
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Figure(3, "Triangle"), a(a), b(b), c(c), A(A), B(B), C(C) {
	}
	void print_info() const override {
		Figure::print_info();
		std::cout << "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
				  << "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
	bool check() const override {
		return (A + B + C == 180);
	}
};

class Quadrangle : public Figure {
protected:
	int a, b, c, d;		// Стороны четырехугольника
	int A, B, C, D;		// Углы четырехугольника
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Figure(4, "Quadrangle"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
	}
	void print_info() const override {
		Figure::print_info();
		std::cout << "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
				  << "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
	bool check() const override {
		return (A + B + C + D == 360);
	}
};

class RightTriangle :public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		nameOfFigure = "Right triangle";
	}
	bool check() const override {
		return Triangle::check() && C == 90;
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
		nameOfFigure = "Isosceles triangle";
	}
	bool check() const override {
		return Triangle::check() && (a == c) && (A == C);
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
		nameOfFigure = "Equilateral triangle";
	}
	bool check() const override {
		return (Triangle::check() && (a == b && b == c) && (A == B && B == C && C == 60));
	}
};

class Rectangle : public Quadrangle {
public:
	Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		nameOfFigure = "Rectangle";
	}
	bool check() const override {
		return Quadrangle::check() && (a == c && b == d) &&
			(A == 90 && B == 90 && C == 90 && D == 90);
	}
};

class Square : public Quadrangle {
public:
	Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
		nameOfFigure = "Square";
	}
	bool check() const override {
		return Quadrangle::check() && (a == b && b == c && c == d) &&
			(A == 90 && B == 90 && C == 90 && D == 90);
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
		nameOfFigure = "Parallelogram";
	}
	bool check() const override {
		return Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D);
	}
};

class Rhombus : public Quadrangle {
public:
	Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {
		nameOfFigure = "Rhombus";
	}
	bool check() const override {
		return Quadrangle::check() && (a == b && b == c && c == d) && (A == C && B == D);
	}
};

void print_info(Figure* F) {
	F->print_info();
}

int main() {
	Triangle t(10, 20, 30, 60, 30, 90);
	RightTriangle rt(10, 20, 30, 40, 45);
	IsoscelesTriangle it(10, 20, 30, 120);
	EquilateralTriangle et(30);
	Quadrangle q(10, 15, 10, 20, 95, 5, 200, 60);
	Square s(10);
	Parallelogram p(30, 40, 60, 120);
	Rhombus r(50, 60, 120);
	Figure f;
	print_info(&t);
	std::cout << std::endl;
	print_info(&rt);
	std::cout << std::endl;
	print_info(&it);
	std::cout << std::endl;
	print_info(&et);
	std::cout << std::endl;
	print_info(&q);
	std::cout << std::endl;
	print_info(&s);
	std::cout << std::endl;
	print_info(&p);
	std::cout << std::endl;
	print_info(&r);
	std::cout << std::endl;
	print_info(&f);
	

	return 0;
}