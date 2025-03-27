#include "AirVehicle.h"

namespace RacingGame {
	AirVehicle::AirVehicle(std::string n, double s) : Vehicle(n, s) {}

	double AirVehicle::getRaceTime(double distance) const {
		return distance / speed;
	}
	std::string AirVehicle::getTypeVehicle() const {
		return "Air";
	}
}

