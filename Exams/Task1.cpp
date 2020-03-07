#include <iostream>

unsigned int biggestFromArray(const unsigned int* arr, unsigned int size) {
	if (arr == nullptr) {
		return 0;
	}

	unsigned int maxNumber = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] > maxNumber) {
			maxNumber = arr[i];
		}
	}

	return maxNumber;
}

unsigned int safelyInputNatural() {
	unsigned int number = 0;

	do {
		std::cin >> number;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	} while (true);

	return number;
}

int main() {
	std::cout << "Enter a size of an array of natural numbers: ";
	unsigned int size = safelyInputNatural();

	if (size < 1) {
		std::cout << "Error!" << std::endl;
		return 0;
	}

	std::cout << "Enter " << size << " natural numbers:" << std::endl;
	unsigned int* numbers = new unsigned int[size];

	for (int i = 0; i < size; i++) {
		numbers[i] = safelyInputNatural();
	}

	unsigned int maxNumber = biggestFromArray(numbers, size);
	std::cout << std::endl << "Biggest from array is: " << maxNumber << std::endl;

	delete[] numbers;
	return 0;
}