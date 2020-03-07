#include <iostream>

bool isInNumber(int digit, int number) {
	bool isInNumber = false;

	while (number) {
		int currentDigit = number % 10;

		if (digit == currentDigit) {
			isInNumber = true;
		}

		number /= 10;
	}

	return isInNumber;
}

bool haveSimilarNumbers(int number1, int number2) {
	bool similar = true;

	while (number1) {
		int currentDigit = number1 % 10;

		if (!isInNumber(currentDigit, number2)) {
			similar = false;
		}

		number1 /= 10;
	}

	return similar;
}

int main() {
	int number1 = 0, number2 = 0;
	std::cin >> number1 >> number2;

	std::cout << haveSimilarNumbers(number1, number2);

	return 0;
}
