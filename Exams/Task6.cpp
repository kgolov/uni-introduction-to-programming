#include <iostream>

int sumOfDigits(int number) {
	if (number < 0) {
		return -1;
	}

	int sum = 0;

	while (number) {
		sum += number % 10;

		number /= 10;
	}

	return sum;
}

int main() {
	int number1 = 5;
	int number2 = 97;
	int number3 = 404;

	std::cout << sumOfDigits(number1) << " " << sumOfDigits(number2) << " " << sumOfDigits(number3) << std::endl;

	return 0;
}