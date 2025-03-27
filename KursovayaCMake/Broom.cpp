#include "Broom.h"

namespace RacingGame {
	Broom::Broom() : AirVehicle("Метла", 20) {}

	double Broom::getAdjustedDistance(double distance) const {
		double coef = 1 - ((static_cast<int>(distance / 1000)) * 0.01);
		if (coef < 0) coef = 0;
		return distance * coef;
	}
}