#include "Carpet.h"

namespace RacingGame {

	Carpet::Carpet() : AirVehicle("Ковер-самолет", 10) {}

	double Carpet::getAdjustedDistance(double distance) const {
		if (distance < 1000) {
			return distance;
		}
		else if (distance < 5000) {
			return distance * 0.97;
		}
		else if (distance < 10000) {
			return distance * 0.90;
		}
		else {
			return distance * 0.95;
		}
	}
}