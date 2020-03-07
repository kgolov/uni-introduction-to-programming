#include <iostream>

int sumOfElementsAbove(const int size, const int* matrix) {
	if (matrix == nullptr || size < 1) {
		return -1;
	}

	int sum = 0;

	for (int row = 0; row < size - 1; row++) {
		for (int col = 0; col < size - row - 1; col++) {
			sum += *(matrix + row * size + col);
		}
	}

	return sum;
}

int main() {
	int matrix[3][3] = { {1, 2, 3},
						 {4, 5, 6},
						 {7, 8, 9} };

	std::cout << sumOfElementsAbove(3, (int*)matrix) << std::endl;

	return 0;
}