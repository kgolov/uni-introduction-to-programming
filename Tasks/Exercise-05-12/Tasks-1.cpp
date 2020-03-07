#include <iostream>

const int MAX_SIZE = 100;

void reverseArray(int* source, int* destination, const int size) {
	if (source == nullptr || destination == nullptr) {
		return;
	}

	int destinationIndex = size - 1;
	int sourceIndex = 0;
	
	while (destinationIndex >= 0) {
		destination[destinationIndex] = source[sourceIndex];
		destinationIndex--;
		sourceIndex++;
	}
}

bool areEqual(int* arr1, int* arr2, const int size) {
	if (arr1 == nullptr || arr2 == nullptr) {
		return false;
	}
	bool areEqual = true;
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			areEqual = false;
		}
	}
	return areEqual;
}

bool isPalindrome(int* arr, const int size) {
	if (arr == nullptr) {
		return false;
	}
	int reversed_arr[MAX_SIZE] = {};
	reverseArray(arr, reversed_arr, size);

	return areEqual(arr, reversed_arr, size);
}

int main() {
	int numbers[4] = { 5, 4, 3, 5 };
	int reversed[4] = {};

	std::cout << isPalindrome(numbers, 4) << std::endl;

	return 0;
}