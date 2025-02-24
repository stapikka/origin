#include <iostream>

class Figure {
private:
	int numOfSides;
	std::string name;
protected:
	Figure(int n, std::string name) {
		numOfSides = n;
		this->name = name;
	}
public:
	int get_sides() {
		return numOfSides;
	}
	std::string get_name() {
		return name;
	}
	Figure() { numOfSides = 0; name = "Figure"; }
};

class Triangle : public Figure {
private:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) :Figure(3, "Triangle") {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	int get_side_a() const { return a; }
	int get_side_b() const { return b; }
	int get_side_c() const { return c; }
	int get_angle_A() const { return A; }
	int get_angle_B() const { return B; }
	int get_angle_C() const { return C; }

};

class Quadrangle : public Figure {
public:
	Quadrangle() :Figure(4, "Quadrangle") {}
};

class RightTriangle :public Triangle {
public:

};

int main() {
	Figure f1;
	Triangle t1(12, 20, 30, 50, 60, 70);
	Quadrangle q1;

	std::cout << t1.get_name() << ": Sides: a = " << t1.get_side_a() << std::endl;
	
	return 0;
}