#include <iostream>
#include <iomanip>

int** transpose(int size, const int* matrix) {
	if (size < 1 || matrix == nullptr) {
		return nullptr;
	}

	int** newMatrix = new int*[size];
	for (int i = 0; i < size; i++) {
		newMatrix[i] = new int[size];
	}

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			newMatrix[col][row] = *(matrix + row*size + col);
		}
	}

	return newMatrix;
}

int main() {
	int matrix[4][4] = { { -2, -5, 12, 1 },
						 { 0, 1, 5, 9 },
						 { 15, 12, -9, 5 },
						 { 11, 13, 4, -4} };

	int** transposed = transpose(4, (int*)matrix);

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			std::cout << std::setw(3) << matrix[row][col] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			std::cout << std::setw(3) << transposed[row][col] << ' ';
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		delete[] transposed[i];
	}

	delete[] transposed;

	return 0;
}