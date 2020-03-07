#include <iostream> 

int main() {
	const int ROWS = 3;
	const int COLS = 3;
	int arr[ROWS][COLS] = { {1, 2, 3},
							{4, 5, 6},
							{7, 8, 9} };

	int sumsOfColumns[COLS] = {};

	for (int col = 0; col < COLS; col++) {
		for (int row = 0; row < ROWS; row++) {
			sumsOfColumns[col] += arr[row][col];
		}
	}

	for (int i = 0; i < COLS; i++) {
		std::cout << sumsOfColumns[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}