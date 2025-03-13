#pragma once
#include <string>
#include <stdexcept>

class FigureExceptions : public std::domain_error {
public:
	explicit FigureExceptions(const std::string& error_message);
};