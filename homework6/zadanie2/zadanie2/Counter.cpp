#include "Counter.h"

Counter::Counter() : value(1) {}

Counter::Counter(int userval) : value(userval) {}

void Counter::incrementor() {
	value++;
}
void Counter::decrementor() {
	value--;
}
int Counter::getvalue() const {
	return value;
}