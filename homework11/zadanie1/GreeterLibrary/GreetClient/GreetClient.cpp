#include<iostream>
#include<string>
#include "Greeter.h"

int main() {
		
	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	GreeterLibrary::Greeter hello;
	std::cout << hello.greet(name) << std::endl;

	return 0;
}