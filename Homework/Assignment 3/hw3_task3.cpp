/**
*
* Solution to homework assignment 3
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
#include <iomanip>

// Defines the size of the vectors we will be working with, can be changed.
const int DIM = 4;

// Checks if a number is an integer or a floating point number.
bool isInteger(const double number) {
	return (floor(number) == number);
}

// Aims to make as much numbers in a matrix integers by finding suitable numbers to divide or multiply a row by.
// Can be slow, but we are not focused on speed here.
void integerify(double matrix[DIM][DIM]) {
	if (matrix == nullptr) {
		return;
	}

	// Scan every row of the matrix.
	for (int row = 0; row < DIM; row++) {
		int numberOfNonIntegers = 0;
		for (int col = 0; col < DIM; col++) {
			// If we find a non-integer, record this occurence.
			if (!isInteger(matrix[row][col])) {
				numberOfNonIntegers++;
			}
		}

		// For every row, if we find even one non-integer, we will aim to round it.
		if (numberOfNonIntegers != 0) {
			// A temporary array to store the result of each attempted multiplication or division.
			double tempRow[DIM] = {};

			// Start attempting multipications with multipliers from to to 25.
			for (int multiplier = 2; multiplier <= 25; multiplier++) {
				// Multiply the current row with the current multiplier, and store the results in tempRow.
				for (int col = 0; col < DIM; col++) {
					tempRow[col] = matrix[row][col] * multiplier;
				}

				// A variable to store the new number of non-integers.
				int newNumber = 0;
				// Check if the number of non-integers has decreased by storing the new number in the new variable.
				for (int col = 0; col < DIM; col++) {
					if (!isInteger(tempRow[col])) {
						newNumber++;
					}
				}

				// If the new number of non-integers is smaller, preserve this multiplication
				if (newNumber < numberOfNonIntegers) {
					// Save the tempRow elements as elements of the main matrix.
					for (int col = 0; col < DIM; col++) {
						matrix[row][col] = tempRow[col];
					}

					// Record the new number of non-integers for this row.
					numberOfNonIntegers = newNumber;
				}
				// Else, do not preserve the multiplication

				// Check if we have reached zero non-integer numbers for the current row
				// If so, we do not need to multiply any more.				
				if (numberOfNonIntegers == 0) {
					break;
				}
				// It is possible that we will not find a multiplier, such that there are no 
				// non-integer numbers in the current row.
			}

			// Same operation with division, starting however from the biggest divisors to the smaller ones.
			// This aims to divide the whole row by the greatest common divisor of all the elements from it, not
			// to reduce the number of non-integers, because this is not possible by division.
			for (int divisor = 25; divisor >= 2; divisor--) {
				// Divide the current row with the current divisor, and store the results in tempRow.
				for (int col = 0; col < DIM; col++) {
					tempRow[col] = matrix[row][col] / divisor;
				}

				// A variable to store the new number of non-integers.
				int newNumber = 0;
				// Calculate the new number of non-integers in the current row.
				for (int col = 0; col < DIM; col++) {
					if (!isInteger(tempRow[col])) {
						newNumber++;
					}
				}

				// If we have found a divisor such that it leaves no non-integer numbers after the division,
				// we have found the greatest common divisor of the row (up to 25).
				// In this case, preserve this division and exit the division loop.
				if (newNumber == 0) {
					// Save the tempRow elements as elements of the main matrix.
					for (int col = 0; col < DIM; col++) {
						matrix[row][col] = tempRow[col];
					}

					// End the division loop.
					break;
				}
			}
		}		
	}

	// After scanning every row of the matrix and attempting various multiplications and divisions with the numbers
	// 2 - 25, we have reached the most satisfactory matrix possible.
}

// Safely inputs an integer from the console.
int safelyInputNumber() {
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

// Returns the absolute value of a floating point number.
double absolute(const double number) {
	return (number >= 0) ? number : -number;
}

// Enters a given number of vectors, (number < DIM), as rows in a matrix.
void enterVectors(const int number, double matrix[DIM][DIM]) {
	if (number < 1 || number > DIM || matrix == nullptr) {
		return;
	}

	for (int row = 0; row < number; row++) {
		for (int col = 0; col < DIM; col++) {
			matrix[row][col] = safelyInputNumber();
		}
	}
}

// Prints a matrix on screen with suitable spacing between elements,
// but only the rows which are not all empty.
void printMatrix(double matrix[DIM][DIM]) {
	if (matrix == nullptr) {
		return;
	}

	for (int row = 0; row < DIM; row++) {
		// Firstly, check if all elements in the row are zeroes.
		bool isEmpty = true;

		for (int col = 0; col < DIM; col++) {
			if (matrix[row][col] != 0) {
				isEmpty = false;
			}
		}

		// If there is an element which is not zero, print the line. Else, do not do anything.
		if (!isEmpty) {
			for (int col = 0; col < DIM; col++) {
				std::cout << std::setprecision(3) << std::setw(5) << matrix[row][col];
			}
			std::cout << std::endl;
		}
	}
}

// Calculates and returns the dimension of a matrix, that has already been transformed with Gauss elimination.
int findDimension(double matrix[DIM][DIM]) {
	if (matrix == nullptr) {
		return -1;
	}

	// The starting position of the dimension (the most possible) is the size of the two-dimension array which 
	// holds the matrix.
	int dimension = DIM;

	// Check if there are empty rows.
	for (int row = 0; row < DIM; row++) {
		bool isEmpty = true;

		for (int col = 0; col < DIM; col++) {
			if (matrix[row][col] != 0) {
				isEmpty = false;
			}
		}

		// If there are empty rows, decrease the dimension variable.
		if (isEmpty) {
			dimension--;
		}
	}

	// Return the calculated number.
	return dimension;
}

// Calculates and fills an array with 
// the Fundamental Set of Solutions (FSS) to a homogenous set of linear equations.
void findFSS(double matrix[DIM][DIM], double FSS[DIM][DIM]) {
	if (matrix == nullptr || FSS == nullptr) {
		return;
	}

	// Calculate the dimension of the input matrix
	int dimMatrix = findDimension(matrix);
	// Calculate the dimension of the FSS, by subtracting the dimension of the input matrix from the biggest
	// dimension possible.
	int dimFSS = DIM - dimMatrix;

	// Initialize variables and arrays to store where we will need a parameter, and where not, 
	// to find the solutions to the set of equations.
	int parameterLocations[DIM] = {};
	int knownVariables[DIM] = {};

	// Determine where we need parameters and where not.
	// Start by traversing the matrix from its last row and rightmost element.
	for (int row = dimMatrix - 1; row >= 0; row--) {
		// Initialize a counter, because we want to calculate parameters only once for every row.
		int counter = 0;
		// Find a suitable column for a known variable. We do this by traversing the row from the right 
		// to find and element which is not zero, and is not already a parameter, or a known variable.
		for (int col = DIM - 1; col >= 0; col--) {
			// If we have already calculated parameters for this row, stop the cycle.
			if (counter == 1) {
				break;
			}

			// If the current element is zero, or it is already a parameter or a known variable,
			// skip this iteration.
			if (matrix[row][col] == 0 || knownVariables[col] == 1 || parameterLocations[col] == 1) {
				continue;
			}
			else {
				// Else, we will now calculate parameters. Record that by incrementing our counter.
				counter++;
			}

			// Save the current element as a known (calculable) value.
			knownVariables[col] = 1;

			// Check elements before (to the left) of our current element. If they are not zero, they will need
			// a parameter, in order to calculate later.
			for (int colBefore = col - 1; colBefore >= 0; colBefore--) {
				if (matrix[row][colBefore] != 0) {
					// Save the occurence of this parameter.
					parameterLocations[colBefore] = 1;
				}
			}
		}
	}

	// Check if we have a parameter or a known Variable for every element in the current row.
	// If not, we will need to add a parameter there as well, as not being one of the two is a problem
	// for our calculations later.
	for (int i = 0; i < DIM; i++) {
		if (parameterLocations[i] == 0 && knownVariables[i] == 0) {
			parameterLocations[i] = 1;
		}
	}

	// For every vector from our FSS, add ones and zeroes to the needed parameter locations, such that
	// every parameter has only one "1" value, and all others are zero.
	for (int i = 0; i < dimFSS; i++) {
		for (int j = 0; j < DIM; j++) {
			if (parameterLocations[j] == 1) {
				FSS[i][j] = 1;
				parameterLocations[j] = 0;
				break;
			}
		}
	}

	// Traverse every row of the FSS to fill the empty cells (calculable Variables) accordingly.
	for (int rowFSS = 0; rowFSS < dimFSS; rowFSS++) {
		// Save the calculable variables in a temporary array, as we will need to alter it, but 
		// the original must not be modified in order to be used by the next iteration.
		int knownTemp[DIM] = {};
		// Copy all elements of knownVariables in knownTemp.
		for (int i = 0; i < DIM; i++) {
			knownTemp[i] = knownVariables[i];
		}

		// Now, for every row of the original matrix, calculate the calculable variables.
		// Start from the last row.
		for (int rowMatrix = dimMatrix - 1; rowMatrix >= 0; rowMatrix--) {
			// Start from the rightmost column.
			for (int col = DIM - 1; col >= 0; col--) {
				// If the current element is a calculable variable and it is not zero, proceed.
				if (knownTemp[col] == 1 && matrix[rowMatrix][col] != 0) {
					// Add to the according FSS cell, the value of all the elements left to the current one,
					// multiplied by the value of the same spot from our current FSS row.
					for (int colBefore = col - 1; colBefore >= 0; colBefore--) {
						FSS[rowFSS][col] += matrix[rowMatrix][colBefore] * FSS[rowFSS][colBefore];
					}
					// The same for all the elements right to the current one.
					// (Effectively, we are solving this linear equation with the given parameters, for
					// the variable matrix[rowMatrix][col].)
					for (int colAfter = col + 1; colAfter < DIM; colAfter++) {
						FSS[rowFSS][col] += matrix[rowMatrix][colAfter] * FSS[rowFSS][colAfter];
					}
					// Divide the achieved sum by the current element's value.
					FSS[rowFSS][col] /= -matrix[rowMatrix][col];

					// Signal that the current element was calculated.
					knownTemp[col] = 0;
				}
			}
		}
	}

	// Because the above algorithm has found the Fundamental Set of Solutions, but it may leave negative 
	// zeroes (-0.0), change all of those to regular zeroes so as not to cause any calculation problems later.
	for (int row = 0; row < dimFSS; row++) {
		for (int col = 0; col < DIM; col++) {
			if (absolute(FSS[row][col]) == 0.0) {
				FSS[row][col] = 0.0;
			}
		}
	}

	// We have filled the given array FSS with the FSS of the vectors in the matrix.
}

// Performs Gauss elimination on a square matrix.
void gauss(double matrix[DIM][DIM]) {
	if (matrix == nullptr) {
		return;
	}

	for (int col = 0; col < DIM; col++) {
		// Search for maximum in this column
		double maxEl = absolute(matrix[col][col]);
		int maxRow = col;
		for (int row = col + 1; row < DIM; row++) {
			if (absolute(matrix[row][col]) > maxEl) {
				maxEl = absolute(matrix[row][col]);
				maxRow = row;
			}
		}

		// Swap maximum row with current row (column by column)
		for (int maxCol = col; maxCol < DIM; maxCol++) {
			double temp = matrix[maxRow][maxCol];
			matrix[maxRow][maxCol] = matrix[col][maxCol];
			matrix[col][maxCol] = temp;
		}

		// If the current element is matrix zero, skip it.
		if (matrix[col][col] == 0) {
			continue;
		}

		// Make all rows below this one 0 in current column
		for (int row = col + 1; row < DIM; row++) {
			double multiplier = -matrix[row][col] / matrix[col][col];
			for (int toChange = col; toChange < DIM + 1; toChange++) {
				if (col == toChange) {
					matrix[row][toChange] = 0;
				}
				else {
					matrix[row][toChange] += multiplier * matrix[col][toChange];
				}
			}
		}
	}
}

// The required function to find a basis for U+W
void findBasis(double vectorsA[DIM][DIM], double vectorsB[DIM][DIM], double basis[DIM][DIM]) {
	if (vectorsA == nullptr || vectorsB == nullptr || basis == nullptr) {
		return;
	}

	// Perform Gauss elimination on vectorsB, to prepare it to find its Fundamental Set of Solutions.
	gauss(vectorsB);

	// A matrix which will hold the vectors from the FSS of vectorsB.
	double FSS[DIM][DIM] = {};

	// Use our written function to populate the array with a FSS.
	findFSS(vectorsB, FSS);

	// Perform Gauss elimination on vectorsA, to prepare it to combine its vectors with the vectors from FSS.
	gauss(vectorsA);

	// Calculate the dimension of the vectorsA matrix.
	int dimA = findDimension(vectorsA);

	// Copy vectors from vectorsA to basis
	int row;
	for (row = 0; row < dimA; row++) {
		for (int col = 0; col < DIM; col++) {
			basis[row][col] = vectorsA[row][col];
		}
	}

	// Copy vectors from the FSS to basis (effectively combining them)
	for (; row < DIM; row++) {
		for (int col = 0; col < DIM; col++) {
			basis[row][col] = FSS[row - dimA][col];
		}
	}

	// Perform one last Gauss elimination on the combined vectors, to find a basis for U+W.
	gauss(basis);

	// Because the nature of this algorithm is such that in many cases we get a matrix with many non-integer 
	// numbers, we will aim to reduce their number with a function which looks for suitable numbers to 
	// multiply the rows by, or divide them, up to 25.
	// This may slow down the program, but not so significantly, and we will get a "prettier" output.
	integerify(basis);
}

int main() {
	// Enter m and n as per the task.
	std::cout << "m = ";
	int m = safelyInputNumber();
	std::cout << "n = ";
	int n = safelyInputNumber();

	// If we have entered negative numbers, or numbers bigger than DIM, print an error and exit.
	if (m < 1 || m > DIM || n < 1 || n > DIM) {
		std::cout << std::endl << 
			"Error! Please enter numbers bigger than 0 and smaller than " << DIM + 1 << "!" << std::endl;
		
		// Return an error code.
		return -1;
	}

	// New line for aesthetic purposes
	std::cout << std::endl;
	// A matrix for the vectors from U (called vectorsA).
	double vectorsA[DIM][DIM] = {};
	// Fill the matrix.
	std::cout << "Enter vectors a1 to a" << n << ": " << std::endl;
	enterVectors(n, vectorsA);

	// New line for aesthetic purposes
	std::cout << std::endl;
	// A matrix for the vectors whose coordinates will be coefficients of a homogenous set of linear equations, 
	// whose space of solutions will be called W.
	double vectorsB[DIM][DIM] = {};
	// Fill the matrix.
	std::cout << "Enter vectors b1 to b" << m << ": " << std::endl;
	enterVectors(m, vectorsB);

	// Find a basis for U+W using our written function
	// Firstly declare a matrix for the results
	double basis[DIM][DIM] = {};
	// Use function
	findBasis(vectorsA, vectorsB, basis);

	// Print our resulting vectors, but only the ones that are not all zeroes.
	std::cout << std::endl << "A basis for U+W are the vectors: " << std::endl;
	printMatrix(basis);

	return 0;
}