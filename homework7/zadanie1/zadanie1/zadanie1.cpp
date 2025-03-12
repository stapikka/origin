#include <iostream>

#define MODE 1

#ifndef MODE
#error MODE is not defined!
#endif

#if MODE == 1
int add(int x, int y) {
	return x + y;
}
#endif

int main() {
	setlocale(LC_ALL, "Russian");

#if MODE == 0
		std::cout << "Работаю в режиме тренировки.\n";

#elif MODE == 1
		int a{}, b{};
		std::cout << "Работаю в боевом режиме.\n";
		std::cout << "Введите два числа!\n";
		std::cin >> a >> b;
		std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
		std::cout << "Неизвестный режим. Завершение работы.\n";
#endif
	return 0;
}