#include "LeaverDynamic.h"
#include <iostream>
#include <string>

int main() {

	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	LeaverDynamicLibrary::Leaver bye;

	std::cout << bye.leave(name) << std::endl;

	return 0;
}