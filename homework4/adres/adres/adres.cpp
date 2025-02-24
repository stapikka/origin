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

	std::string get_output_address() const {
		return city + ", " + street + ", " + std::to_string(homenumber) + ", " + std::to_string(flatnumber);
	}
};

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

	std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Error!" << std::endl;
		for (int i = 0; i < n; ++i) {
			delete[] addresses[i];
		}
		delete[] addresses;
		return 1;
	}

	for (int i = n - 1; i >= 0; --i) {
		fout << addresses[i]->get_output_address() << std::endl;
		delete addresses[i];
	}
	delete[] addresses;
	fout.close();

	return 0;
}