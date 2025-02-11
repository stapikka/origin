#include <iostream>

struct BankAccount {
    int AccNumber;
    std::string OwnerName;
    double balance;
};

void ChangeBalance(BankAccount* rub, double newBal) {
    rub->balance = newBal;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    BankAccount rub;

    std::cout << "Введите номер вашего счета: ";
    std::cin >> rub.AccNumber;
    std::cout << "Введите ваше имя: ";
    std::cin >> rub.OwnerName;
    std::cout << "Введите текущий баланс: ";
    std::cin >> rub.balance;

    double newBal;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBal;

    ChangeBalance(&rub, newBal);

    std::cout << "Ваш счет: " << rub.AccNumber << ", " << rub.OwnerName << ", " << rub.balance << std::endl;

    return 0;
}
