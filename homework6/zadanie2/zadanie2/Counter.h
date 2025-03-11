#pragma once

class Counter {
private:
	int value;
public:
	Counter();
	Counter(int userval);
	void incrementor();
	void decrementor();
	int getvalue() const;
};