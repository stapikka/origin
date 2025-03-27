#include "Eagle.h"

namespace RacingGame {
	Eagle::Eagle() : AirVehicle("Орел", 8) {}

	double Eagle::getAdjustedDistance(double distance) const {
		return distance * 0.94;
	}
}