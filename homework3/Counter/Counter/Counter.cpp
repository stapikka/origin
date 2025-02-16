#include <iostream>

class Counter {
	int value;
public:
	Counter() { value = 1; };
	Counter(int userval) { value = userval; }
	void incrementor() { value++; } 
	void decrementor() { value--; }
	int getvalue() const { return value; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	int startval{};
	std::string choise{};
	std::string command{};
	Counter* mycounter = nullptr;
	
	while (true) {
		std::cout << "Желаете ли вы установить собственное значение? Введите y или n: ";
		std::cin >> choise;
		if (choise == "y" || choise == "Y") {
			std::cout << "Введите начальное значение: ";
			std::cin >> startval;
			mycounter = new Counter(startval);
			break;
		}
		else if(choise == "n" || choise == "N")
		{
			mycounter = new Counter();
			break;
		}
		else {
			std::cout << "Введено некорректное значение.Попробуйте снова!\n";
		}
	}

	while (!(command == "x")) {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;
		if (command == "+") {
			mycounter->incrementor();
		}
		else if (command == "-") {
			mycounter->decrementor();
		}
		else if (command == "=") {
			std::cout << "Ваше значение равно: " << mycounter->getvalue() << std::endl;
		} 
		else if (command == "x") {
			std::cout << "До свидания!\n";
		}
		else {
			std::cout << "Нераспознанная команда.\n";
		}
		
	}
	delete mycounter;

	return 0;
}