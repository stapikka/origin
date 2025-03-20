#pragma once
#include <string>
#ifdef LEAVERDYNAMICLIBRARY_EXPORTS
#define LEAVERDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define LEAVERDYNAMICLIBRARY_API __declspec(dllimport)
#endif
namespace LeaverDynamicLibrary
{
	class Leaver {
	public:
		LEAVERDYNAMICLIBRARY_API std::string leave(std::string name);
	};
}