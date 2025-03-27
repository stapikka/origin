#pragma once
#include "Vehicle.h"

namespace RacingGame {

	class AirVehicle : public Vehicle {
	public:
		AirVehicle(std::string n, double s);

		double getRaceTime(double distance) const override;

		virtual double getAdjustedDistance(double distance) const = 0;

		std::string getTypeVehicle() const override;
	};
}