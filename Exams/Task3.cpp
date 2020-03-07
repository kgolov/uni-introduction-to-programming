#include <iostream>

float sumOfUnevenIndexes(float* numbers, int size) {
	if (numbers == nullptr) {
		return -1.0F;
	}

	if (size < 2) {
		return 0.0F;
	}

	float sum = 0;

	for (int i = 1; i < size; i += 2) {
		sum += numbers[i];
	}

	return sum;
}

int main() {
	float arr1[1] = { 2.05f };
	float arr2[3] = { 1.01f, 2.02f, 3.03f };
	float arr3[4] = { 1.699f, 2.221f, 3.338f, 0.0067f };

	std::cout << sumOfUnevenIndexes(arr1, 1) << std::endl;
	std::cout << sumOfUnevenIndexes(arr2, 3) << std::endl;
	std::cout << sumOfUnevenIndexes(arr3, 4) << std::endl;

	return 0;
}