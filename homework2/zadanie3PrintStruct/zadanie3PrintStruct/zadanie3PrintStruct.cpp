#include <iostream>

struct Address {
    std::string city;
    std::string street;
    int homenumber;
    int apartnumber;
    int index;
};

void PrintAddress(const Address& anyaddress) {
    std::cout << "City: " << anyaddress.city << std::endl;
    std::cout << "Street: " << anyaddress.street << std::endl;
    std::cout << "Home Number: " << anyaddress.homenumber << std::endl;
    std::cout << "Apart Number: " << anyaddress.apartnumber << std::endl;
    std::cout << "Index: " << anyaddress.index << std::endl;
    std::cout << std::endl;
}

int main()
{
    Address MyHome{ "Saint-P", "Liteyniy", 15, 1, 123456 };
    Address ObamaHome{ "Liberty City", "Obama str.", 2000, 100, 000000 };
    PrintAddress(MyHome);
    PrintAddress(ObamaHome);

    return 0;
}
