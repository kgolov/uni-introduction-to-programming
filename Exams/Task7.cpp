#include <iostream>

int* combineTwoArrays(int* arr1, int* arr2, int size1, int size2) {
	if (arr1 == nullptr || arr2 == nullptr || size1 < 1 || size2 < 1) {
		return nullptr;
	}

	int* newArray = new int[size1 + size2];

	int firstIndex = 0;
	int secondIndex = 0;
	int combined = 0;

	while (firstIndex < size1 && secondIndex < size2) {
		if (arr1[firstIndex] <= arr2[secondIndex]) {
			while (arr1[firstIndex] <= arr2[secondIndex] && firstIndex < size1) {
				newArray[combined] = arr1[firstIndex];
				combined++;
				firstIndex++;
			}
		}
		if (arr2[secondIndex] <= arr1[firstIndex]) {
			while (arr2[secondIndex] <= arr1[firstIndex] && secondIndex < size2) {
				newArray[combined] = arr2[secondIndex];
				combined++;
				secondIndex++;
			}
		}
	}

	// If we are out of the loop, we have reached the end of one array
	if (firstIndex == size1 && secondIndex < size2) {
		while (secondIndex < size2) {
			newArray[combined] = arr2[secondIndex];
			combined++;
			secondIndex++;
		}
	}
	else if (firstIndex < size1 && secondIndex == size2) {
		while (firstIndex < size1) {
			newArray[combined] == arr1[firstIndex];
			combined++;
			firstIndex++;
		}
	}

	return newArray;
}

int main() {
	int numbers1[6] = { 3, 3, 5, 7, 12, 15 };
	int numbers2[10] = { -4, -1, 0, 3, 3, 12, 20, 21, 25, 99 };

	int* newSortedArray = combineTwoArrays(numbers1, numbers2, 6, 10);

	for (int i = 0; i < 16; i++) {
		std::cout << newSortedArray[i] << " ";
	}
	std::cout << std::endl;

	delete[] newSortedArray;
	return 0;
}