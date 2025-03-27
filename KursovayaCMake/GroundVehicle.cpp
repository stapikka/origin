#include "GroundVehicle.h"

namespace RacingGame {

	GroundVehicle::GroundVehicle(std::string n, double s, double tbfr, const std::vector<double>& durationRest)
		: Vehicle(n, s), timeBeforeRest(tbfr), durationOfRest(durationRest) {}
	double GroundVehicle::getRaceTime(double distance) const {
		double time = distance / speed;
		int countOfRest = static_cast<int>(time / timeBeforeRest);

		double totalRestTime = 0;	// Общее время отдыха за всю гонку
		for (int i = 0; i < countOfRest; ++i) {
			if (i < durationOfRest.size()) {
				totalRestTime += durationOfRest[i];
			}
			else {
				totalRestTime += durationOfRest.back();
			}
		}
		return time + totalRestTime;
	}
	std::string GroundVehicle::getTypeVehicle() const {
		return "Ground";
	}
}