#pragma once
#include <string>

namespace RacingGame {

	class Vehicle {
	protected:
		std::string name;
		double speed;
	public:
		Vehicle(std::string n, double spd);

		virtual double getRaceTime(double distance) const = 0;

		virtual std::string getTypeVehicle() const = 0;

		std::string getName() const;

		virtual ~Vehicle();

	};
}