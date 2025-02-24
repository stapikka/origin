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
public:
	Triangle() :Figure(3, "Triangle") {}
};

class Quadrangle : public Figure {
public:
	Quadrangle() :Figure(4, "Quadrangle") {}
};

int main() {
	Figure f1;
	Triangle t1;
	Quadrangle q1;

	std::cout << "Number of sides:\n";
	std::cout << f1.get_name() << ": " << f1.get_sides() << std::endl;
	std::cout << t1.get_name() << ": " << t1.get_sides() << std::endl;
	std::cout << q1.get_name() << ": " << q1.get_sides() << std::endl;
	return 0;
}