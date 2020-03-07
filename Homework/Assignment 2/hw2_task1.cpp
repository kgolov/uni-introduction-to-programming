/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 1
* @compiler VC
*
*/

#include <iostream>

// A function to calculate absolute value of integer
int absolute(int number) {
	return (number > 0) ? number : -number;
}

// The required function to shift elements of an array
void moveElements(int* arr, int length, int toMove) {
	if (arr == nullptr) {
		return;
	}

	if (toMove > 0) {
		// We will be moving elements to the right

		// A loop to shift the array right a toMove number of times, each time by one element.
		for (int i = 0; i < toMove; i++) {
			// Save the last element of the array, so it won't be lost.
			// We will put it in the beginning after the loop is done.
			int element = arr[length-1];

			// A loop to shift every element one position to the right.
			for (int j = length - 2; j >= 0; j--) {
				arr[j + 1] = arr[j];
			}

			// Put the saved last element in the beginning.
			arr[0] = element;
		}
	}
	else if (toMove < 0) {
		// We will be moving elements to the left
		toMove = absolute(toMove);

		// A loop to shift the array left a toMove number of times, each time by one element.
		for (int i = 0; i < toMove; i++) {
			// Save the first element of the array, so it won't be lost.
			// We will put it in the end after the loop is done.
			int element = arr[0];

			// A loop to shift every element one position to the left.
			for (int j = 1; j < length; j++) {
				arr[j - 1] = arr[j];
			}

			// Put the saved first element in the end.
			arr[length - 1] = element;
		}
	}
	// Else,
	// If toMove is zero, we do not need to do anything.
}

// A function to print an array on screen
void printArray(const int* arr, int length) {
	if (arr == nullptr) {
		return;
	}

	std::cout << "Arr: {";

	for (int i = 0; i < (length - 1); i++) {
		std::cout << arr[i] << ", ";
	}

	// We output the last element out of the loop, because we do not want
	// to add a comma and space in the end
	std::cout << arr[length - 1] << "}" << std::endl;
}

// A function to safely input an integer
int safelyInputInteger() {
	int number = 0;

	do {
		std::cin >> number;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	} while (true);	

	return number;
}

// A function to create and fill an array of a given size
int* createArray(int size) {
	if (size < 1) {
		return nullptr;
	}

	// Declare a dynamic array of the given size
	int* numbers = new int[size];

	// Fill the array with a loop
	for (int i = 0; i < size; i++) {
		numbers[i] = safelyInputInteger();
	}

	// Return the pointer to the array
	return numbers;
}

int main() {
	// Input a number to indicate the size of our array
	std::cout << "Enter a size for the array: ";
	int size = safelyInputInteger();
	// Check if it is a valid number, otherwise throw an error and end the program
	if (size < 1) {
		// Print an error
		std::cout << "Error!" << std::endl;
		// End the program
		return 0;
	}

	// Create and fill an array of that size
	std::cout << "Enter " << size << " integers to fill the array: " << std::endl;	
	int* Arr = createArray(size);

	// Input a number to shift the array that many times
	std::cout << "Input an integer to shift the array: ";
	int shift = safelyInputInteger();
	// New line for aesthetic purposes
	std::cout << std::endl;

	// If the absolute value of the integer entered is bigger than the array, we 
	// throw an Error and end the program.
	if (absolute(shift) > size) {
		// Print an error
		std::cout << "Error!" << std::endl;

		// Don't forget to free the allocated memory!
		delete[] Arr;
		// End program
		return 0;
	}

	// Use our written function moveElements
	moveElements(Arr, size, shift);

	// Print array on screen
	printArray(Arr, size);

	// Free the allocated memory for our array
	delete[] Arr;

	// End program
	return 0;
}