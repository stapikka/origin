#include <iostream>
#include <string>

class Vehicle {
protected:
	std::string name;
	double speed;
public:
	Vehicle(std::string n, double spd) : name (n), speed(spd) {}

	bool operator==(const Vehicle& other) const {
		return name == other.name && speed == other.speed;
	}

	virtual double getRaceTime(double distance) const = 0;

	virtual std::string getTypeVehicle() const = 0;

	std::string getName() const { return name; }

	virtual ~Vehicle() {}

};

class GroundVehicle : public Vehicle {
protected:
	double timeBeforeRest;			// время движения до отдыха
	double durationOfRest[3];	// Длительности отдыха
	int restCount;				// Количество отдыхов

public:
	GroundVehicle(std::string n, double s, double tbfr, const double durationRestArr[], int rCount)
			: Vehicle(n, s), timeBeforeRest(tbfr), restCount(rCount) {
		for (int i = 0; i < restCount; ++i) {
			durationOfRest[i] = durationRestArr[i];
		}
	}
	double getRaceTime(double distance) const override {
		double time = distance / speed;
		int countOfRest = static_cast<int>(time / timeBeforeRest);
		

		double totalRestTime = 0;	// Общее время отдыха за всю гонку
		for (int i = 0; i < countOfRest; ++i) {
			if (i < restCount) {
				totalRestTime += durationOfRest[i];
			}
			else {
				totalRestTime += durationOfRest[restCount - 1];
				// вот тут у меня warning Reading invalid data from 'this->durationOfRest':  the readable size is '24' bytes, but '-8' bytes may be read.
				// прошу подсказать как его можно исправить
			}
			
		}
		return time + totalRestTime;
	}
	std::string getTypeVehicle() const override {
		return "Ground";
	}
};

class Camel : public GroundVehicle {
public:
	Camel() : GroundVehicle("Верблюд", 10, 30, restTimes, 2) {}
private:
	static constexpr double restTimes[2] = { 5, 8 };
};

class FastCamel : public GroundVehicle {
public:
	FastCamel() : GroundVehicle("Верблюд-быстроход", 40, 10, restTimes, 3) {}
private:
	static constexpr double restTimes[3] = { 5, 6.5, 8 };
};

class Centaur : public GroundVehicle {
public:
	Centaur() : GroundVehicle("Кентавр", 15, 8, restTimes, 1) {}
private:
	static constexpr double restTimes[] = { 2 };

};

class Boots : public GroundVehicle {
public:
	Boots() : GroundVehicle("Ботинки-вездеходы", 6, 60, restTimes, 2) {}
private:
	static constexpr double restTimes[2] = { 10, 5 };
};

class AirVehicle : public Vehicle {
public:
	AirVehicle(std::string n, double s) : Vehicle(n, s) {}

	double getRaceTime(double distance) const override {
		return distance / speed;
	}

	virtual double getAdjustedDistance(double distance) const = 0;

	std::string getTypeVehicle() const override {
		return "Air";
	}
};

class Carpet : public AirVehicle {
public:
	Carpet() : AirVehicle("Ковер-самолет", 10) {}

	double getAdjustedDistance(double distance) const override {
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
};

class Eagle : public AirVehicle {
public:
	Eagle() : AirVehicle("Орел", 8) {}

	double getAdjustedDistance(double distance) const override {
		return distance * 0.94;
	}
};

class Broom : public AirVehicle {
public:
	Broom() : AirVehicle("Метла", 20) {}

	double getAdjustedDistance(double distance) const override {
		double coef = 1 - ((static_cast<int>(distance / 1000)) * 0.01);
		if (coef < 0) coef = 0;
		return distance * coef;
	}
};

class Race {
private:
	double distance;
	int raceType;						// Тип гонки (1 - назменая, 2 - воздушная, 3 - смешанная)
	Vehicle* participants[7] = {};		// Участники гонки
	int participantsCount;
public:
	Race(double dist, int rtype) : distance(dist), raceType(rtype), participantsCount(0) {}


	void registerVehicle(int coiseVehicle) {
	
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

		for (int i = 0; i < participantsCount; ++i) {
			if (*participants[i] == *vehicle) {
				std::cout << "Нельзя зарегистрировать одно и то же ТС дважды!\n";
				return;
			}
		}

		if (participantsCount >= 7) {
			std::cout << "Максимальное количество учатсников достигнуто!\n";
			return;
		}
		std::string vehicleType = vehicle->getTypeVehicle();

		if ((raceType == 1 && vehicleType == "Ground") ||
				(raceType == 2 && vehicleType == "Air") ||
				(raceType == 3)) {
			participants[participantsCount++] = vehicle;
			std::cout << "ТС успешно зарегистрировано!\n";
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспорта!\n";
		}

		std::cout << "Зарегистрированные ТС: ";
		for (int i = 0; i < participantsCount; ++i) {
			std::cout << participants[i]->getName() << " ";
		}
		std::cout << std::endl;
	}

	void start() {
		if (participantsCount < 2) {
			std::cout << "Должно быть зарегистрировано хотя бы 2 ТС\n";
			return;
		}
		for (int i = 0; i < participantsCount; ++i) {
			for (int j = i + 1; j < participantsCount; ++j) {
				if (participants[i]->getRaceTime(distance) > participants[j]->getRaceTime(distance)) {
					std::swap(participants[i], participants[j]);
				}
			}
		}
		std::cout << "Результаты гонки:\n";
		for (int i = 0; i < participantsCount; ++i) {
			std::cout << i + 1 << ". " << participants[i]->getName()
					<< ". Время: " << participants[i]->getRaceTime(distance) 
					<< std::endl;
		}
	}

	int getParticipantsCount() const { return participantsCount; }

	~Race() {
		for (int i = 0; i < participantsCount; ++i) {
			delete participants[i];
		}
	}
};


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