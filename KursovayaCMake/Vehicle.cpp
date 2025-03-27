#include "C:\Users\balun\Desktop\LessonsNetoBase\KursovayaCMake\Vehicle.h"

namespace RacingGame {

	Vehicle::Vehicle(std::string n, double spd) : name(n), speed(spd) {}

	std::string Vehicle::getName() const { return name; }

	Vehicle::~Vehicle() {}
}