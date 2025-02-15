#include <iostream>

class Counter {
	int value;
public:
	void incrementor() { value++; } 
	void decrementor() { value--; }
	int getvalue() const { return value; }
	void set_default_val() { value = 1; }
	void set_user_val(int userval) { value = userval; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	int startval{};
	std::string choise{};
	std::string command{};
	Counter mycount1{};
	
	while (true) {
		std::cout << "Желаете ли вы установить собственное значение? Введите y или n: ";
		std::cin >> choise;
		if (choise == "y" || choise == "Y") {
			std::cout << "Введите начальное значение: ";
			std::cin >> startval;
			mycount1.set_user_val(startval);
			break;
		}
		else if(choise == "n" || choise == "N")
		{
			mycount1.set_default_val();
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
			mycount1.incrementor();
		}
		else if (command == "-") {
			mycount1.decrementor();
		}
		else if (command == "=") {
			std::cout << "Ваше значение равно: " << mycount1.getvalue() << std::endl;
		} 
		else if (command == "x") {
			std::cout << "До свидания!\n";
		}
		else {
			std::cout << "Нераспознанная команда.\n";
		}
		
	}
	
	return 0;
}