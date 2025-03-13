#include "FigureExceptions.h"

FigureExceptions::FigureExceptions(const std::string& error_message)
	: std::domain_error("Ошибка создания фигуры. Причина: " + error_message) {}