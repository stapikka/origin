#include "Race.h"

namespace RacingGame {
	Race::Race(double dist, int rtype) : distance(dist), raceType(rtype) {}

	void Race::registerVehicle(int coiseVehicle) {

		Vehicle* vehicle = nullptr;
		switch (coiseVehicle) {
		case 1:
			vehicle = new Camel();
			break;
		case 2:
			vehicle = new FastCamel();
			break;
		case 3:
			vehicle = new Centaur();
			break;
		case 4:
			vehicle = new Boots();
			break;
		case 5:
			vehicle = new Carpet();
			break;
		case 6:
			vehicle = new Eagle();
			break;
		case 7:
			vehicle = new Broom();
			break;
		default:
			std::cout << "Неизвестное ТС. Попробуйте снова!\n";
			return;
		}

		for (auto p : participants) {
			if (p->getName() == vehicle->getName()) {
				std::cout << "Нельзя зарегистрировать одно и то же ТС дважды!\n";
				delete vehicle;
				return;
			}
		}

		if (participants.size() >= 7) {
			std::cout << "Максимальное количество учатсников достигнуто!\n";
			delete vehicle;
			return;
		}
		std::string vehicleType = vehicle->getTypeVehicle();

		if ((raceType == 1 && vehicleType == "Ground") ||
			(raceType == 2 && vehicleType == "Air") ||
			(raceType == 3)) {
			participants.push_back(vehicle);
			std::cout << "ТС успешно зарегистрировано!\n";
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспорта!\n";
			delete vehicle;
		}

		std::cout << "Зарегистрированные ТС: ";
		for (auto p : participants) {
			std::cout << p->getName() << " ";
		}
		std::cout << std::endl;
	}

	void Race::start() {
		if (participants.size() < 2) {
			std::cout << "Должно быть зарегистрировано хотя бы 2 ТС\n";
			return;
		}
		for (int i = 0; i < participants.size(); ++i) {
			for (int j = i + 1; j < participants.size(); ++j) {
				if (participants[i]->getRaceTime(distance) > participants[j]->getRaceTime(distance)) {
					std::swap(participants[i], participants[j]);
				}
			}
		}
		std::cout << "Результаты гонки:\n";
		for (int i = 0; i < participants.size(); ++i) {
			std::cout << i + 1 << ". " << participants[i]->getName()
				<< ". Время: " << participants[i]->getRaceTime(distance)
				<< std::endl;
		}
	}

	int Race::getParticipantsCount() const { return participants.size(); }

	Race::~Race() {
		for (auto p : participants) {
			delete p;
		}
	}
}