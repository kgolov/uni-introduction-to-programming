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

int isHacksaw(int* arr, int size) {
	if (arr == nullptr || size < 1) {
		return -1;
	}
	bool isHacksaw = true;

	if (size == 1) {
		return isHacksaw;
	}

	short int operation = 0; // will be 1 if searching for a bigger number or -1 if searching for a smaller number

	if (arr[0] > arr[1]) {
		// the first number is bigger than the second, after that we will be searching for a bigger again
		operation = 1;
	}
	else if (arr[0] < arr[1]) {
		// the first number is smaller than the second, after that we will be searching for a smaller again
		operation = -1;
	}
	else {
		// the first number is equal to the second, that means the sequence is not a hacksaw
		isHacksaw = false;
		return isHacksaw;
	}

	for (int i = 1; i < size - 1; i++) {
		if (operation == 1) {
			if (arr[i + 1] > arr[i]) {
				// the next number is bigger, so we are still in a Hacksaw sequence
			}
			else {
				// the next number is smaller, so we are not in a Hacksaw sequence
				isHacksaw = false;
				return isHacksaw;
			}
		}
		if (operation == -1) {
			if (arr[i + 1] < arr[i]) {
				// the next number is smaller, so we are still in a Hacksaw sequence
			}
			else {
				// the next number is bigger, so we are not in a Hacksaw sequence
				isHacksaw = false;
				return isHacksaw;
			}
		}
		operation *= -1;
	}
	return isHacksaw;
}

int main() {
	const int MAX_ELEMENTS = 100;
	int arr[MAX_ELEMENTS] = {};
	int size = enterElements(arr);
	std::cout << isHacksaw(arr, size);

	return 0;
}