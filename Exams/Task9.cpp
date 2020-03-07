#include <iostream>

void printRectangle(int width, int height) {
	const int maxWidth = 80;
	const int maxHeight = 25;
	const char character = '*';

	if (width < 1 || height < 1 || width > maxWidth || height > maxHeight) {
		std::cout << "Error" << std::endl;
		return;
	}

	// Calculate and center vertically
	int emptyRows = (maxHeight - height) / 2;

	// Print emptyRows
	for (int row = 0; row < emptyRows; row++) {
		std::cout << std::endl;
	}

	// Calculate and center horizontallyy
	int emptySpaces = (maxWidth - width) / 2;

	// Print rectangle
	for (int row = 0; row < height; row++) {
		// Print empty spaces
		for (int i = 0; i < emptySpaces; i++) {
			std::cout << ' ';
		}
		// Print characters
		for (int col = 0; col < width; col++) {
			std::cout << character;
		}
		// Print new line
		std::cout << std::endl;
	}

	// Print emptyRows
	for (int row = 0; row < emptyRows; row++) {
		std::cout << std::endl;
	}
}

int main() {
	printRectangle(50, 15);

	return 0;
}