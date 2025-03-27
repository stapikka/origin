#pragma once
#include <vector>
#include <string>
#include "Vehicle.h"

namespace RacingGame {

	class GroundVehicle : public Vehicle {
	protected:
		double timeBeforeRest;			// время движения до отдыха
		std::vector<double> durationOfRest;	// Длительности отдыха

	public:
		GroundVehicle(std::string n, double s, double tbfr, const std::vector<double>& durationRest);
		double getRaceTime(double distance) const override;
		std::string getTypeVehicle() const override;
	};
}