#include <iostream>

double averageOfNElements(int* elements, int size) {
	double result = 0;
	for (int i = 0; i < size; i++) {
		result += elements[i];
	}
	result /= size;
	return result;
}

int enterNElements(int* elements) {	
	int numberOfElements = 0;
	do {
		std::cin >> numberOfElements;
	} while (numberOfElements < 1 || numberOfElements > 100);

	for (int i = 0; i < numberOfElements; i++) {
		std::cin >> elements[i];
	}

	return numberOfElements;
}

int main() {
	const int MAX_ELEMENTS = 100;

	int elements[MAX_ELEMENTS];

	int numberOfElements = enterNElements(elements);

	double average = averageOfNElements(elements, numberOfElements);

	std::cout << average << std::endl;

	return 0;
}