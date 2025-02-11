#include <iostream>

enum months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

std::string GetMonthName(int mon) {
    switch (static_cast<months>(mon)) {
    case months::January: return "Январь";
    case months::February: return "Февраль";
    case months::March: return "Март";
    case months::April: return "Апрель";
    case months::May: return "Май";
    case months::June: return "Июнь";
    case months::July: return "Июль";
    case months::August: return "Август";
    case months::September: return "Сентябрь";
    case months::October: return "Октябрь";
    case months::November: return "Ноябрь";
    case months::December: return "Декабрь";
    default:               return "Неправильный номер месяца!";
    }
}

int main()
{
    setlocale(0, "");

    int monthnum{};

    do {
        std::cout << "Введите номер месяца:";
        std::cin >> monthnum;

        if (monthnum == 0) {
            std::cout << "Всего доброго!" << std::endl;
            break;
        }

        std::cout << GetMonthName(monthnum) << std::endl;
    } while (monthnum != 0);

    return 0;
}
