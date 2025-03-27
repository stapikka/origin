#pragma once
#include "AirVehicle.h"

namespace RacingGame {

	class Carpet : public AirVehicle {
	public:
		Carpet();

		double getAdjustedDistance(double distance) const override;
	};
}