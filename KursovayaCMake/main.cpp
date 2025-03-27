#include <iostream>
#include <string>
#include <vector>
#include "Race.h"

using namespace RacingGame;

int main() {

	setlocale(LC_ALL, "rus");

	while (true) {
		double distance;
		int raceType;

		std::cout << "Добро пожаловать!\n"
			<< "1. Гонка для наземного транспорта\n"
			<< "2. Гонка для воздушного транспорта\n"
			<< "3. Гонка для наземного и воздушного транспорта\n"
			<< "Выберите тип гонки: ";
		std::cin >> raceType;
		if (raceType < 1 || raceType > 3) {
			std::cout << "Выбран некорректный тип гонки.\n";
			continue;
		}

		std::cout << "\nВведите длину дистанции: ";
		std::cin >> distance;

		Race race(distance, raceType);

		while (true) {
			std::cout << "\nВыберите действие: \n"
				<< "1 - Зарегистрировать ТС\n"
				<< "0 - Начать гонку\n";
			int mainchoise{};
			std::cin >> mainchoise;
			if (mainchoise == 0 && race.getParticipantsCount() < 2) {
				std::cout << "Минимальное количество участников - 2\n";
			}
			if (mainchoise == 1) {

				if (raceType == 1) {
					std::cout << "Гонка для наземного транспорта. Расстояние: "
						<< distance << std::endl;
				}
				else if (raceType == 2) {
					std::cout << "Гонка для наземного транспорта. Расстояние: "
						<< distance << std::endl;
				}
				else {
					std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: "
						<< distance << std::endl;
				}
				std::cout << std::endl;
				std::cout << "Выберите тс для регистрации:\n"
					<< "1. Верблюд\n"
					<< "2. Верблюд-быстроход\n"
					<< "3. Кентавр\n"
					<< "4. Ботинки-вездеходы\n"
					<< "5. Ковер-самолет\n"
					<< "6. Орел\n"
					<< "7. Метла\n"
					<< "0. Завершить регистрацию\n";
				int coiseVehicle;
				std::cin >> coiseVehicle;

				if (coiseVehicle == 0) {
					break;
				}

				race.registerVehicle(coiseVehicle);
			}
			else if (mainchoise == 0) {
				if (race.getParticipantsCount() < 2) {
					std::cout << "\nЗарегистрировано менее 2 участников!\n";
					continue;
				}
				race.start();
				break;
			}
			else {
				std::cout << "Некорректный выбор.\n";
			}
		}

		int choisecontinue;
		std::cout << "Хотите провести еще одну гонку?\n"
			<< "1. Да\n"
			<< "0. Нет\n";
		std::cin >> choisecontinue;
		if (choisecontinue != 1) {
			break;
		}

	}
	return 0;
}