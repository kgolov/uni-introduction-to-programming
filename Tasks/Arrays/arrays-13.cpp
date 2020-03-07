#include <iostream>

int enterElements(int* arr) {
	if (arr == nullptr) {
		return -1;
	}

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	return n;
}

void displayPartOfArray(int* arr, int startingIndex, int length) {
	if (arr == nullptr) {
		return;
	}

	for (int i = startingIndex; i < (startingIndex + length); i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	const int MAX_SIZE = 100;
	int numbers[MAX_SIZE] = {};

	int size = enterElements(numbers);

	int currentStartingIndex = 0;
	int maxStartingIndex = currentStartingIndex;
	int currentLength = 1;
	int maxLength = currentLength;

	for (int i = 0; i < size - 1; i++) {
		if (numbers[i] < numbers[i + 1]) {
			currentLength++;
		}
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength;
				maxStartingIndex = currentStartingIndex;
			}

			currentStartingIndex = i + 1;
			currentLength = 1;
		}
	}
	
	if (currentLength > maxLength) {
		maxLength = currentLength;
		maxStartingIndex = currentStartingIndex;
	}

	displayPartOfArray(numbers, maxStartingIndex, maxLength);
	
	return 0;
}