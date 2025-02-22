#include <fstream>
#include <iostream>
#include <string>

class Address {
private:
	std::string city;
	std::string street;
	int homenumber;
	int flatnumber;
public:
	Address(std::string city, std::string street, int homenumber, int flatnumber) {
		this->city = city;
		this->street = street;
		this->homenumber = homenumber;
		this->flatnumber = flatnumber;
	}

	std::string get_output_address() {
		return city + ", " + street + ", " + std::to_string(homenumber) + ", " + std::to_string(flatnumber);
	}

	std::string get_city() { return city; }
};

void sort(Address** addresses, int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (addresses[j]->get_city() > addresses[j + 1]->get_city()) {
				Address* temp = addresses[j];
				addresses[j] = addresses[j + 1];
				addresses[j + 1] = temp;
			}
		}
	}
}

int main() {

	int n{};
	std::ifstream fin("in.txt");
	if (!fin.is_open()) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
	fin >> n;
	fin.ignore();

	Address** addresses = new Address * [n];

	for (int i = 0; i < n; ++i) {
		std::string city, street;
		int home, flat;

		std::getline(fin, city);
		std::getline(fin, street);
		fin >> home >> flat;
		fin.ignore();

		addresses[i] = new Address(city, street, home, flat);
	}
	fin.close();

	sort(addresses, n);

	std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Error!" << std::endl;
		return 1;
	}

	fout << n << std::endl;

	for (int i = 0; i < n; ++i) {
		fout << addresses[i]->get_output_address() << std::endl;
		delete addresses[i];
	}
	delete[] addresses;
	fout.close();

	return 0;
}