#pragma once
#include "AirVehicle.h"

namespace RacingGame {
	class Broom : public AirVehicle {
	public:
		Broom();

		double getAdjustedDistance(double distance) const override;
	};
}