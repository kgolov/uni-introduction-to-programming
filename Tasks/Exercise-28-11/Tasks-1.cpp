#include <iostream>

int main() {
	const int ROWS = 3;
	const int COLS = 3;
	int arr[ROWS][COLS] = { {1, 2, 3},
							{4, 5, 6},
							{7, 8, 9}	};

	for (int col = 0; col < COLS; col++) {
		for (int row = ROWS - 1; row >= (ROWS - col - 1); row--) {

			std::cout << arr[row][col] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}