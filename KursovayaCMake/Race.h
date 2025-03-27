#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "AirVehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Broom.h"

namespace RacingGame {
	class Race {
	private:
		double distance;
		int raceType;						// Тип гонки (1 - назменая, 2 - воздушная, 3 - смешанная)
		std::vector<Vehicle*>participants;		// Участники гонки
	public:
		Race(double dist, int rtype);


		void registerVehicle(int coiseVehicle);

		void start();

		int getParticipantsCount() const;

		~Race();
	};
}
