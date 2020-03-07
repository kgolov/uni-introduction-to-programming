#include <iostream>

int sumOfEvenNumbers(const int* arr, int size) {
	if (arr == nullptr || size < 1) {
		return -1;
	}

	int sum = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}

	return sum;
}

int main() {
	int arr1[1] = { 4 };
	int arr2[3] = { 3, 8, 12 };
	int arr3[9] = { 3, 4, -5, 12, 11, 0, 1, 5, 7 };

	std::cout << sumOfEvenNumbers(arr1, 1) << std::endl;
	std::cout << sumOfEvenNumbers(arr2, 3) << std::endl;
	std::cout << sumOfEvenNumbers(arr3, 9) << std::endl;

	return 0;
}