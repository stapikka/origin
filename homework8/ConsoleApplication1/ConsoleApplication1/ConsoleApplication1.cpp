#include <iostream>
#include <string>

int function(std::string str, int forbidden_length) {
    if (!(forbidden_length == str.length())) {
        return str.length();
    }
    throw std::string{ "Вы ввели слово запретной длины! До свидания." };
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string strValue{};
    int length{};
    std::cout << "Введите запретную длину\n";
    std::cin >> length;

    do {
        std::cout << "Введите слово\n";
        std::cin >> strValue;

        try {
            std::cout << "Длина слова " << strValue << " = "
                << function(strValue, length) << std::endl;
        }
        catch (std::string& error_messege) {
            std::cout << error_messege << std::endl;
        }
    } while (strValue.length() != length);

    return 0;
}