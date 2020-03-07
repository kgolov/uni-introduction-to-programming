/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 2
* @compiler VC
*
*/


#include <iostream>
#include <iomanip>

// Size of the matrixes to work with (can be changed)
const int N = 3;

// Safely inputs an integer from the keyboard
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

// Prints a matrix on screen
void printMatrix(float matrix[N][N]) {
	if (matrix == nullptr) {
		return;
	}

	// For each element of the matrix, print it on screen, allocating 5 spaces for each one.
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			std::cout << std::setprecision(2) << std::setw(5) << matrix[row][col];
		}
		std::cout << std::endl;
	}
}

// Enters a matrix from the keyboard
void enterMatrix(int matrix[N][N]) {
	if (matrix == nullptr) {
		return;
	}

	// Fill the matrix element by element
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			matrix[row][col] = safelyInputInteger();
		}
	}
}

// Transposes a matrix
// See here for a definition and method of calculation:
// https://en.wikipedia.org/wiki/Transpose
void transpose(int matrix[N][N], int transposed[N][N]) {
	if (matrix == nullptr || transposed == nullptr) {
		return;
	}

	// Flip columns and rows
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			transposed[col][row] = matrix[row][col];
		}
	}
}

// Multiplies a matrix with another matrix
// See here for a definition and method of calculation:
// https://en.wikipedia.org/wiki/Matrix_multiplication#Definition
void multiply(int A[N][N], int B[N][N], int result[N][N]) {
	if (A == nullptr || B == nullptr || result == nullptr) {
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = 0;
			for (int k = 0; k < N; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
// Overload for float matrixes
void multiply(float A[N][N], float B[N][N], float result[N][N]) {
	if (A == nullptr || B == nullptr || result == nullptr) {
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = 0;
			for (int k = 0; k < N; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

// Multiplies a matrix with an integer
// See here for a definition and method of calculation:
// https://en.wikipedia.org/wiki/Matrix_multiplication#Product_with_a_scalar
void multiplyWithNumber(int matrix[N][N], int number, int result[N][N]) {
	if (matrix == nullptr || result == nullptr) {
		return;
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			result[row][col] = number * matrix[row][col];
		}
	}
}

// Adds matrixes together
// See here for a definition and method of calculation:
// https://en.wikipedia.org/wiki/Matrix_addition#Entrywise_sum
void add(int A[N][N], int B[N][N], int result[N][N]) {
	if (A == nullptr || B == nullptr || result == nullptr) {
		return;
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			result[row][col] = A[row][col] + B[row][col];
		}
	}
}

// Stores the minor of matrix[i][j] element in a temporary matrix [][]. dim is the current dimension of matrix.
// See here for a definition of minors and method of calculation:
// https://en.wikipedia.org/wiki/Minor_(linear_algebra)#First_minors
void minor(int matrix[N][N], int temp[N][N], int i, int j, int dim) {
	if (matrix == nullptr || temp == nullptr || i < 0 || j < 0 || dim < 1 || dim > N) {
		return;
	}

	// To store indexes of the temporary matrix
	int tempRow = 0;
	int tempCol = 0;

	// Loop through every element of matrix[][]
	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			// Save to the temporary matrix only those elements, which are not on the i-th row or j-th column.
			if (row != i && col != j) {
				temp[tempRow][tempCol] = matrix[row][col];

				// Increment tempCol by one
				tempCol++;

				// Check if the row is filled in the temporary matrix
				if (tempCol == dim - 1) {
					// Reset the column index and increment row index
					tempCol = 0;
					tempRow++;
				}
			}
		}
	}

	// Resulting, in the temp matrix we have minor of the element matrix[i][j].
}

// Calculates the determinant of a matrix recursively, where dim is the current dimension of the matrix.
// For a definition of determinant of matrix, see here: https://en.wikipedia.org/wiki/Determinant
// For method of calculation, look up Laplace expansion. See here:
// https://en.wikipedia.org/wiki/Laplace_expansion
int determinant(int matrix[N][N], int dim) {
	if (matrix == nullptr || dim < 1 || dim > N) {
		return -1;
	}

	// Base case: if the dimension is 1, return the only element of the matrix
	if (dim == 1) {
		return matrix[0][0];
	}

	// Calculate the determinant by expanding the matrix by its first row.
	// (Laplace expansion)
	// More on the topic can be found here: https://en.wikipedia.org/wiki/Laplace_expansion
	int result = 0; // To add here
	int sign = 1;   // To store the sign multiplier
	for (int i = 0; i < dim; i++) {
		// A temporary matrix to store the cofactors
		int temp[N][N] = {};

		// Calculate the minor of the element matrix[0][i]
		minor(matrix, temp, 0, i, dim);
		
		// Add to the sum the term (-1)^(0+i) * matrix[0][i] * det(temp)
		result += sign * matrix[0][i] * determinant(temp, dim - 1);

		// The next term needs to be added with an opposite sign.
		sign *= -1;
	}

	// The result sum is the required determinant.
	return result;
}

// Calculate an adjoint matrix for use in the calculation of an inverse matrix
// See here for a definition of adjoint matrix and method of calculation:
// https://www.varsitytutors.com/hotmath/hotmath_help/topics/adjoint-of-a-matrix
void adjoint(int matrix[N][N], int adj[N][N]) {
	if (matrix == nullptr || adj == nullptr) {
		return;
	}

	int sign = 1; // A variable to store the sign of adj[row][col]
	int temp[N][N] = {}; // A temporary matrix to store minors of matrix elements

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			// Get the minor of matrix[row][col]
			minor(matrix, temp, row, col, N);

			// The sign of adj[row][col] will be positive if the sum of row+col is even
			if ((row + col) % 2 == 0) {
				sign = 1; 
			}
			else {
				sign = -1;
			}

			// Save the element, changing the rows with the columns in order to get the transpose 
			// of the cofactor matrix ( the adjoint matrix )
			adj[col][row] = sign * determinant(temp, N - 1);
		}
	}

	// The resulting matrix - adj[][] is the adjoint matrix of matrix[][].
}

// Calculate the inverse matrix of a matrix
// Returns false if the matrix is singular (determinant = 0),
// or true if the matrix is invertible (determinant != 0).
// See here for a definition and method of calculation:
// https://en.wikipedia.org/wiki/Invertible_matrix#Analytic_solution
bool inverse(int matrix[N][N], float inverse[N][N]) {
	if (matrix == nullptr || inverse == nullptr) {
		return false;
	}

	// Calculate the determinant of matrix[][]
	int det = determinant(matrix, N);

	// If the determinant is 0, the matrix is singular and non-invertible
	if (det == 0) {
		inverse = {};
		return false;
	}

	// If the determinant is not 0, we can find its inverse
	// Find the adjoint matrix
	int adj[N][N] = {};
	adjoint(matrix, adj);

	// Find the inverse using the formula inverse = adj/det (see here for clarification):
	// https://en.wikipedia.org/wiki/Invertible_matrix#Analytic_solution
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			inverse[row][col] = adj[row][col] / (float)det;
		}
	}

	// We have found the inverse matrix
	return true;
}

// Solves the equation XA = (-3)At*C - 5X
void solve(int A[N][N], int C[N][N], float X[N][N]) {
	if (A == nullptr || C == nullptr || X == nullptr) {
		return;
	}

	/* The following are equivalent:
		XA = (-3)At*C - 5X
		XA + X5 = (-3)(At*C)
		X(A + 5*E) = (-3)(At*C)

		Let's call the matrixes A + 5*E = S and (-3)*(At*C) = T.
		Then,
		XS = T
		X  = T*S' (where S' is the inverse of S)

		We have found X.
	*/

	// Firstly, let's transpose A.
	int At[N][N] = {};
	transpose(A, At);

	// Then, let's multiply At and C and call that temp1.
	int temp1[N][N] = {};
	multiply(At, C, temp1);

	// After that, let's multiply temp1 and -3, which gives us T.
	int T[N][N] = {};
	multiplyWithNumber(temp1, -3, T);

	// Declare and fill a local matrix E, which is the identity matrix
	// Directly multiplying it by 5, which can be changed easily with the below constant
	int E[N][N] = {};
	const int multiplier = 5;
	// We do it with a loop for versatility if we want to change sizes easily
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (row == col) {
				E[row][col] = 1 * multiplier;
			}
			else {
				E[row][col] = 0;
			}
		}
	}

	// Add E and A, which gives us S.
	int S[N][N] = {};
	add(A, E, S);
	
	// Finally, we need to find the inverse of S and multiply it with T from the left to find X.
	float Sinv[N][N] = {};
	// Holds the return state of the function inverse
	bool inverseSuccessful = inverse(S, Sinv);
	// If the inverse was not successful (i.e. the matrix was singular), we will stop the function
	if (!inverseSuccessful) {
		// We will return an empty matrix X in order to signal the error.
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				X[row][col] = 0;
			}
		}
		// Stop the function
		return;
	}
	// Else, the inverse was successful and we can find our solution.

	// Multiply T by S' from the right to find X.
	// Easiest to convert T from integer to float is to do it here:
	float Tf[N][N] = {};
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			Tf[row][col] = (float)T[row][col];
		}
	}
	multiply(Tf, Sinv, X);

	// We have found X.
}

int main() {
	// Declare matrixes A and C, which we will fill later.
	int A[N][N] = {};
	int C[N][N] = {};
	// The matrix which will hold the answers.
	float X[N][N] = {};

	// Fill the given matrixes.
	std::cout << "Matrix equation  XA = (-3)At*C - 5X  solver" << std::endl;
	std::cout << "Enter " << N << "x" << N << " matrix A: (line by line, separate integers with spaces)" << std::endl;
	enterMatrix(A);

	std::cout << std::endl;
	std::cout << "Enter " << N << "x" << N << " matrix C: (line by line, separate integers with spaces)" << std::endl;
	enterMatrix(C);

	// Solve the equation.
	solve(A, C, X);
	
	// Print the found solution, after a new line for aestethics
	std::cout << std::endl << "The solution matrix X is:" << std::endl;
	printMatrix(X);

	// End the program.
	return 0;
}