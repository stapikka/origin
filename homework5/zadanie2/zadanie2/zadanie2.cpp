#include <iostream>

class Figure {
public:
	virtual void print_info() const {
		std::cout << "Figure!\n";
	}
};

class Triangle : public Figure {
protected:
	int a, b, c;	// Стороны треугольника
	int A, B, C;	// Углы треугольника
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: a(a), b(b), c(c), A(A), B(B), C(C) {}

	void print_info() const override {
		std::cout << "Triangle:\n"
		<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
		<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}

};

class Quadrangle : public Figure {
protected:
	int a, b, c, d;		// Стороны четырехугольника
	int A, B, C, D;		// Углы четырехугольника
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

	void print_info() const override {
		std::cout << "Quadrangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
	
};

class RightTriangle :public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {}

	void print_info() const override {
		std::cout << "Right triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {}

	void print_info() const override {
		std::cout << "Isosceles triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

	void print_info() const override {
		std::cout << "Equilateral triangle:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << "\n";
	}
};

class Square : public Quadrangle {
public:
	Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {}

	void print_info() const override {
		std::cout << "Square:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

	void print_info() const override {
		std::cout << "Parallelogram:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
};

class Rhombus : public Quadrangle {
public:
	Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {}

	void print_info() const override {
		std::cout << "Rhombus:\n"
			<< "Sides: a = " << a << " b = " << b << " c = " << c << " d = " << d << "\n"
			<< "Angles: A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n";
	}
};

void print_info(Figure* F) {
	F->print_info();
}

int main() {
	Triangle t(10, 20, 30, 30, 30, 30);
	RightTriangle rt(10, 20, 30, 45, 45);
	IsoscelesTriangle it(10, 20, 30, 120);
	EquilateralTriangle et(30);
	Quadrangle q(10, 15, 10, 20, 95, 5, 200, 60);
	Square s(10);
	Parallelogram p(30, 40, 60, 120);
	Rhombus r(50, 60, 120);
	print_info(&t);
	print_info(&rt);
	print_info(&it);
	print_info(&et);
	print_info(&q);
	print_info(&s);
	print_info(&p);
	print_info(&r);

	return 0;
}