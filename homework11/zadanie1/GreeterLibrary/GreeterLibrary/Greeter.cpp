#include "Greeter.h"
namespace GreeterLibrary
{
	std::string Greeter::greet(std::string name) {
		std::string greet = "Hello, " + name + "!";
		return greet;
	}
}