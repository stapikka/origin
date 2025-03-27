#pragma once
#include "AirVehicle.h"

namespace RacingGame {
	class Eagle : public AirVehicle {
	public:
		Eagle();

		double getAdjustedDistance(double distance) const override;
	};
}