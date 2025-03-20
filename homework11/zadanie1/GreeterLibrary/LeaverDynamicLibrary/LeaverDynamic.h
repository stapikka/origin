#pragma once
#include <string>
#ifdef LEAVERDYNAMICLIBRARY_EXPORTS
#define GREETERLIBRARY_API __declspec(dllexport)
#else
#define GREETERLIBRARY_API __declspec(dllimport)
#endif
namespace LeaverDynamicLibrary
{
	class Leaver {
	public:
		std::string leave(std::string name);
	};
}