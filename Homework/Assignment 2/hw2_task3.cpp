/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 3
* @compiler VC
*
*/

#include <iostream>

// Declare a global constant for the size of the square matrix
const int SIZE = 6;

// A function to calculate absolute value of integer
int absolute(int number) {
	return (number > 0) ? number : -number;
}

// A function to calculate the number of digits in a number
int numberOfDigits(int number) {
	int result = 0;

	// The do-while loop is necessary in order to return 1 digits when the number is 0
	do {
		number /= 10;
		result++;
	} while (number);

	return result;
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

/* A function which will be called from the bigger one, 
   which searches only rows or columns in one direction

   PARAMETERS: 
   + The Matrix to check
   + An array of digits to check against
   + Length of the array of digits
   + Bool Row: True if checking a row, False if checking a column
   + Bool Direction: True if going right or down, False if going left or up
   RETURNS:
   + The number of occurences of the number in the given rows or columns in that direction  */
int oneWayCheck(const int matrix[SIZE][SIZE], const int* digits, int length, bool row, bool direction) {
	if (matrix == nullptr || digits == nullptr) {
		return -1;
	}

	// A variable to store the occurences
	int occurences = 0;

	// A loop to get rows or columns individually
	for (int index = 0; index < SIZE; index++) {
		// Initialise a variable to iterate with, it is different depending on 
		// which direction we are looking (right or left, up or down)
		int firstIndex = direction ? 0 : SIZE - 1;

		// A loop to go through the elements of the row/col individually and check against the digits
		// Its condition is adjusted according to the direction again
		while ( 
			// If going right or down
			(direction && firstIndex < SIZE) ||
			// If going left or up
			(!direction && firstIndex >= 0) 
			) {

			// Initialize a variable to iterate the digits array with
			int secondIndex = 0;

			// An if statement to check when we match numbers
			// Its condition is adjusted according to whether we are checking a row or column
			if (
				// If checking a row
				(row && matrix[index][firstIndex] == digits[secondIndex]) ||
				// If checking a column
				(!row && matrix[firstIndex][index] == digits[secondIndex])
				) {

				// The first digit of the number matches
				// Save the firstIndex as a temporary variable, because if the whole number is not found
				// we need to revert to it.
				int temp = firstIndex;

				// A loop to check every digit of the number against the ones in the matrix
				// Again a double check depending on row/column and direction
				while (
					// Depending on row or column
					((row && matrix[index][firstIndex] == digits[secondIndex]) ||
					 (!row && matrix[firstIndex][index] == digits[secondIndex]))
					// Checks to see if we have reached the end of the number
					&& secondIndex < length && 
					// Depending on direction
					((direction && firstIndex < SIZE) ||
					 (!direction && firstIndex >= 0))
					) {

					// Update both indexes
					// Depending on direction
					if (direction) {
						firstIndex++;
					}
					else {
						firstIndex--;
					}
					secondIndex++;
				}

				// The loop has finished. If we are at the end of the number, this 
				// means that we have found the whole of it.
				if (secondIndex == length) {
					// Save this as an occurence.
					occurences++;

					// Decrement or increment firstIndex because it was last incremented / decremented.
					// (Depending on direction)
					if (direction) {
						firstIndex--;
					}
					else {
						firstIndex++;
					}
				}
				else {
					// We have not found the whole number. Revert to the previous index and start again.
					firstIndex = temp;
				}
			}
			
			// Update our iterator, depending on direction
			if (direction) {
				firstIndex++;
			} 
			else {
				firstIndex--;
			}
		}
	}

	// Return the found number of occurences of the number in the given row/column and direction
	return occurences;
}

/* The required function which checks whether a matrix is simplified, and then
   searches for occurences of a number when reading rows or columns both ways.

   PARAMETERS:
   + The Matrix to check
   + A number to search for
   RETURNS:
   + The number of occurences of the number in the matrix in every direction */
int searchMatrix(const int matrix[SIZE][SIZE], int number) {
	if (matrix == nullptr) {
		return -2;
	}

	// Check if matrix is simplified
	bool simplified = true;
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			// Run through every element in the matrix and if we find a number smaller than 0 or bigger than 9,
			// set the flag that the matrix is not simplified.
			if (matrix[row][col] < 0 || matrix[row][col] > 9) {
				simplified = false;
			}
		}
	}

	// If the matrix is not simplified, stop the function and return an error code of -1
	if (!simplified) {
		return -1;
	}

	// Convert the passed number to positive only
	number = absolute(number);
	// Check if the number is longer than SIZE digits, if so it cannot be found in the matrix.
	// Also calculate the number of digits in the number for future use.
	int length = numberOfDigits(number);
	if (length > SIZE) {
		// Return the number of occurences, which is zero. Stop the function.
		return 0;
	}

	// Save the digits of the number in an array
	int digits[SIZE] = {};
	for (int i = length - 1; i >= 0; i--) {
		digits[i] = number % 10;
		number /= 10;
	}

	// Variable to store the number of occurences of the number
	int occurences = 0;

	// Begin checking the matrix
	// Firstly, check every row when going right
	occurences += oneWayCheck(matrix, digits, length, true, true);
	// Then, check every row when going left
	occurences += oneWayCheck(matrix, digits, length, true, false);	

	// Then, check every column when going down
	occurences += oneWayCheck(matrix, digits, length, false, true);
	// Last, check every column when going up
	occurences += oneWayCheck(matrix, digits, length, false, false);	

	// Return the number of occurences of the number in the matrix.
	return occurences;
}

/* A function to fill a square matrix with a constant size of SIZE with integers */
void fillMatrix(int matrix[SIZE][SIZE]) {
	if (matrix == nullptr) {
		return;
	}

	// Employ two for loops to input an integer into each cell
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			matrix[row][col] = safelyInputInteger();
		}
	}

	// Matrix is filled.
}

int main() {
	// Declare the given matrix of numbers with a constant size of SIZE
	int numbers[SIZE][SIZE] = { };
	// Fill the matrix with numbers from the keyboard
	std::cout << "Please enter elements for a " << SIZE << "x" << SIZE << " matrix of integers" << std::endl;
	std::cout << "You can separate elements with spaces and new lines: " << std::endl;
	fillMatrix(numbers);

	// Input a number to search for in the matrix.
	std::cout << "Enter a number to search for in the matrix: ";
	int number = safelyInputInteger();

	// Employ our written function, searchMatrix, to find the number of occurences of the number in the matrix.
	int occurences = searchMatrix(numbers, number);
	
	// Print the number of occurences on the screen.
	std::cout << std::endl << "Occurences of the number: " << occurences << std::endl;

	// End the program.
	return 0;
}