#include <iostream>

class Calculator {
	double num1, num2;
	
public:
	double add() { return num1 + num2; }

	double multiply() { return num1 * num2; }

	double subtract_1_2() { return num1 - num2; }

	double subtract_2_1() { return num2 - num1; }

	double divide_1_2() { return num1 / num2; }

	double divide_2_1() { return num2 / num1; }

	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		return false;
	}

	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		return false;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	double n1{}, n2{};
	Calculator c1{};
	while (true) {

		std::cout << "Ведите num1: ";
		std::cin >> n1;

		while (!c1.set_num1(n1)) {
			std::cout << "Некорректно введенные данные! Попробуйте снова!\n";
			std::cout << "Ведите num1: ";
			std::cin >> n1;
		}

		std::cout << "Ведите num2: ";
		std::cin >> n2;

		while (!c1.set_num2(n2)) {
			std::cout << "Некорректно введенные данные! Попробуйте снова!\n";
			std::cout << "Ведите num2: ";
			std::cin >> n2;
		}

		std::cout << "num1 + num2 = " << c1.add() << std::endl;
		std::cout << "num1 * num2 = " << c1.multiply() << std::endl;
		std::cout << "num1 - num2 = " << c1.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << c1.subtract_2_1() << std::endl;
		std::cout << "num1 / num2 = " << c1.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << c1.divide_2_1() << std::endl;

	}
	
	return 0;
}