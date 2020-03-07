/**
*
* Solution to homework task 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declaring functions which will be reading from the console and validating the input
int safelyInputNumber(int lowerBound = -2147483648, int upperBound = 2147483647);
char safelyInputCharacter();

// Declaring a function which will be used to draw the square
void draw(char, int);

int main() {
	// We define our maximum console Width and Height as constants
	const int consoleWidth = 80;
	const int consoleHeight = 25;
	/* We calculate the maximum size of the square using our consoleWidth and consoleHeight constants:
	    The width and height of the square will be 2 * sideOfSquare - 1, so we need to take the smaller of
	    the two dimensions of the console and solve 2 * sideOfSquare - 1 <= consoleSize.
	   We do this by: adding 1 to it and dividing it by two. */
	const int maxSize = (( (consoleHeight < consoleWidth) ? consoleHeight : consoleWidth) + 1) / 2;

	// We input a character to draw with from the console
	// We do it by our own function safelyInputCharacter() in order to have the user enter another one
	// if it was not valid.
	char c = safelyInputCharacter();

	/* We input an integer for the size of side of the drawn square
	   If the user enters a number smaller than zero or bigger than our maximum allowed size, 
	   we throw an error and terminate the program. */
	int sideOfSquare = safelyInputNumber();
	if (sideOfSquare < 1 || sideOfSquare > maxSize) {
		cout << "Error" << endl;
		return 0;
	}
	
	// We can now calculate the dimensions of our square - the height and width are both 2 * sideOfSquare - 1.
	int sizeOfSquare = 2 * sideOfSquare - 1;

	// We can now start drawing the square. Firstly, we need to calculate how many empty lines
	// we need to print in order to center it vertically, and draw them using a loop.
	int emptyLines = (consoleHeight - sizeOfSquare) / 2;
	for (int i = 0; i < emptyLines; i++) {
		cout << endl;
	}

	// We now define two variables - one named "characters" which starts from 1 and one named 
	// "spaces" which will be calculated as follows: (consoleWidth - characters) / 2 on every line.
	int characters = 1;

	// The following loop starts drawing the top half of the square.
	while (characters <= sizeOfSquare) {
		int spaces = (consoleWidth - characters) / 2;
		// Output the calculated spaces and characters using our written function:
		draw(' ', spaces);
		draw(c, characters);
		// Now, we increment characters by two for the next line.
		characters += 2;
		cout << endl;
	}

	// The following loop starts drawing the bottom half of the square, but before that 
	// we need to subtract 4 from the number of characters (because it was incremented once before by 2)
	characters -= 4;
	while (characters >= 1) {
		int spaces = (consoleWidth - characters) / 2;
		// Output the calculated spaces and characters using our written function:
		draw(' ', spaces);
		draw(c, characters);
		// Now, we decrement characters by two for the next line.
		characters -= 2;
		cout << endl;
	}

	// We have drawn the square, but we need to draw the remaining empty lines below it, 
	// in order to complete the vertical centering.
	for (int i = 0; i < emptyLines; i++) {
		cout << endl;
	}

	// This is the end of the program.
	return 0;
}

/* A function to safely input a number within any range of integers, or a strictly specified one */
int safelyInputNumber(int lowerBound, int upperBound) {
	int number;

	// A loop for continuously reading from the console, until the input meets our requirements
	do {
		cin >> number;

		if (cin.fail()) {
			// If the input fails, we clear the error and try again
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			// If the input did not fail, we will validate the data
			if (number >= lowerBound && number <= upperBound) {
				// Terminate the loop, number is valid
				break;
			}
			// else, do not terminate, number is not valid
		}
	} while (true);

	// We return the last valid number to the main function where it is needed.
	return number;
}

/* A function to safely input a character only */
char safelyInputCharacter() {
	char c;
	
	// A loop for continuously reading from the console, until the input meets our requirements
	do {
		cin >> c;

		if (cin.fail()) {
			// If the input fails, we clear the error and try again
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			// If the input did not fail, we stop the loop.
			break;
		}
	} while (true);

	// We return the now valid character to the main function where it is needed.
	return c;
}

/* A function to output the character c, n times */
void draw(char c, int n) {
	if (n <= 0) {
		// We cannot output the character a negative number of times!
		// Throw an error
		cout << "Error" << endl;
		return;
	}
	// Output the character c, n times
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}