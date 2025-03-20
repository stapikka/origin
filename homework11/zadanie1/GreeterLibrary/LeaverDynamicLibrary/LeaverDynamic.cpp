#include "LeaverDynamic.h"
namespace LeaverDynamicLibrary
{
	std::string Leaver::leave(std::string name) {
		std::string leave = "Goodbye, " + name + "!";
		return leave;
	}
}