#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int gcd(int a, int b) {		// Наибольший общий делитель
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	// Сокращение дроби
	void reduce() {		
		int gcdVal = gcd(numerator_, denominator_);
		numerator_ /= gcdVal;
		denominator_ /= gcdVal;
		if (denominator_ < 0) {
			numerator_ = -numerator_;
			denominator_ = -denominator_;
		}
	}
	// Наименьшее общее кратное
	int lcm(int a, int b) {
		return (a / gcd(a, b)) * b;
	}

public:
	Fraction(int numerator, int denominator)
			: numerator_(numerator), denominator_(denominator) {
		reduce();	// Сокращение при создании
	}
	Fraction() : numerator_(0), denominator_(1) {}
	// Перегрузка +
	Fraction operator+(Fraction other) {
		int lcmVal = lcm(denominator_, other.denominator_);
		int newNumerator = (numerator_ * (lcmVal / denominator_))
			+ (other.numerator_ * (lcmVal / other.denominator_));
		return Fraction(newNumerator, lcmVal);
	}
	// Перегрузка -
	Fraction operator-(Fraction other) {
		int lcmVal = lcm(denominator_, other.denominator_);
		int newNumerator = (numerator_ * (lcmVal / denominator_))
			- (other.numerator_ * (lcmVal / other.denominator_));
		return Fraction(newNumerator, lcmVal);
	}
	// Перегрузка *
	Fraction operator*(Fraction other) {
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
	}
	// Перегрузка /
	Fraction operator/(Fraction other) {
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
	}
	// Унарный минус
	Fraction operator-() const {
		return Fraction(-numerator_, denominator_);
	}
	// Перегрузка ++x
	Fraction& operator++() {
		numerator_ += denominator_;
		reduce();
		return *this;
	}
	// Перегрузка x++
	Fraction operator++(int) {
		Fraction temp = *this;
		numerator_ += denominator_;
		reduce();
		return temp;
	}
	// Перегрузка --x
	Fraction& operator--() {
		numerator_ -= denominator_;
		reduce();
		return *this;
	}
	// Перегрузка x--
	Fraction operator--(int) {
		Fraction temp = *this;
		numerator_ -= denominator_;
		reduce();
		return temp;
	}

	void Print() {
		std::cout << numerator_ << "/" << denominator_ << std::endl;
	}
	int getNum() const { return numerator_; }
	int getDenom() const { return denominator_; }

};

int main() {
	setlocale(LC_ALL, "Russian");

	int num1{};
	int denom1{1};
	int num2{};
	int denom2{ 1 };

	std::cout << "Введите числитель дроби 1: " << std::endl;
	std::cin >> num1;
	do {
		std::cout << "Введите знаменатель дроби 1: " << std::endl;
		std::cin >> denom1;
		if (denom1 <= 0) {
			std::cout << "Введите число больше 0\n";
		}
	} while (denom1 <= 0);

	std::cout << "Введите числитель дроби 2: " << std::endl;
	std::cin >> num2;
	do {
		std::cout << "Введите знаменатель дроби 2: " << std::endl;
		std::cin >> denom2;
		if (denom2 <= 0) {
			std::cout << "Введите число больше 0\n";
		}
	} while (denom2 <= 0);

	Fraction f1(num1, denom1), f2(num2, denom2);
	Fraction result;
	result = f1 + f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " + "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	result = f1 - f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " - "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	result = f1 * f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " * "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	result = f1 / f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " / "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	result = ++f1 * f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " * "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	result = f1-- * f2;
	std::cout << f1.getNum() << "/" << f1.getDenom() << " * "
		<< f2.getNum() << "/" << f2.getDenom() << " = ";
	result.Print();
	std::cout << std::endl;

	return 0;
}