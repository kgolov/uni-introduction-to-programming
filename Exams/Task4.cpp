#include <iostream>

void changeToAverage(int& number) {
	if (number < 0) {
		return;
	}
	
	int average = 0;
	int digits = 0;

	while (number) {
		average += number % 10;

		digits++;

		number /= 10;
	}

	average /= digits;

	number = average;
}

int main() {
	int number1 = 5;
	int number2 = 38;
	int number3 = 72581;

	changeToAverage(number1);
	changeToAverage(number2);
	changeToAverage(number3);

	std::cout << number1 << " " << number2 << " " << number3 << std::endl;

	return 0;
}