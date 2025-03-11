#include "Math_functions.h"
#include <cmath>

int summa(int x, int y) {
	return x + y;
}
int diff(int x, int y) {
	return x - y;
}
int mult(int x, int y) {
	return x * y;
}
double div(double x, double y) {
	return (x / y);
}
int power_2(int x, int y) {
	return std::pow(x, y);
}