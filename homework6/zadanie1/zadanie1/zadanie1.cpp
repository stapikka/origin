#include <iostream>
#include "Math_functions.h"

int main() {
	setlocale(LC_ALL, "Russian");

	int a{};
	int b{};
	int choise{};

	std::cout << "Введите два числа!\n";
	std::cout << "1: ";
	std::cin >> a;
	std::cout << "2: ";
	std::cin >> b;

	std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> choise;

	switch (choise) {
	case(1): 
		std::cout << summa(a, b) << std::endl;
		break;
	case(2): 
		std::cout << diff(a, b) << std::endl;
		break;
	case(3):
		std::cout << mult(a, b) << std::endl;
		break;
	case(4): 
		std::cout << div(static_cast<double>(a), static_cast<double>(b)) << std::endl;
		break;
	case(5): 
		std::cout << a << " В степени " << b << " = " <<
			power_2(a, b) << std::endl;
		break;
	default: 
		std::cout << "Введена неправильная команда!\n";
		break;
	}
	

}