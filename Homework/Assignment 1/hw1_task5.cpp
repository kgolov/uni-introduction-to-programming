/**
*
* Solution to homework task 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

// Declaring a function which will read from the console and validate the input
double safelyInputDouble();

int main() {
	// We define our variables X and Y which are coordinates we will be inputting from the console
	double X = safelyInputDouble();
	double Y = safelyInputDouble();

	// We have a series of checks to perform. If we find out where the point is during these checks,
	// we will be outputting the result.

	// We will be using the formula: if (Xpoint - Xcenter)^2 + (Ypoint - Ycenter)^2 < Radius^2
	// Then the point is in our circle. If they are equal, it is on the border, and if the first part is bigger,
	// it is outside.

	if (X * X + Y * Y > 36) {
		// We are outside the big circle. We output Outside
		cout << "Outside" << endl;
	} 
	else if (X * X + Y * Y == 36) {
		// We are on the border of the circle. We output Undefined
		cout << "Undefined" << endl;
	}
	// We are inside the big circle. Check for smaller ones.
	else if (X * X + (Y - 3) * (Y - 3) < 1) {
		// We are inside the small black circle. We output Black
		cout << "Black" << endl;
	}
	else if (X * X + (Y - 3) * (Y - 3) == 1) {
		// We are on the border of the small black circle. We output Undefined
		cout << "Undefined" << endl;
	}
	else if (X * X + (Y - 3) * (Y - 3) < 9) {
		// We are inside the big white circle. We output White
		cout << "White" << endl;
	} 
	else if (X * X + (Y - 3) * (Y - 3) == 9 &&
			X >= 0) {
		// We are on the border of the big white circle. However, We only output Undefined if X >= 0, 
		// because if we are on the left side of the circle border, we are not in another colour - we are still
		// in the white part.
		cout << "Undefined" << endl;
	}
	else if (X * X + (Y + 3) * (Y + 3) < 1) {
		// We are inside the small white circle. We output White
		cout << "White" << endl;
	}
	else if (X * X + (Y + 3) * (Y + 3) == 1) {
		// We are on the border of the small white circle. We ouput Undefined
		cout << "Undefined" << endl;
	}
	else if (X * X + (Y + 3) * (Y + 3) < 9) {
		// We are inside the big black circle. We output Black
		cout << "Black" << endl;
	} 
	else if (X * X + (Y + 3) * (Y + 3) == 9 &&
			X <= 0) {
		// We are on the border of the big black circle. However, we only output Undefined if X <= 0,
		// because if we are on the right side of the circle border, we are not in another colour - we are
		// still in the black part.
		cout << "Undefined" << endl;
	}
	else if (X < 0) {
		// We are in the remaining white part on the left. We output White
		cout << "White" << endl;
	} 
	else {
		// We must be in the remaining black part on the right. We output Black
		cout << "Black" << endl;
	}

	// We have passed through all the possible scenarios. We end the program
	return 0;
}

/* A function to safely input a double number only */
double safelyInputDouble() {
	double number;

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
			// If the input did not fail, we stop the loop.
			break;
		}
	} while (true);

	// We return the now valid number to the main function where it is needed.
	return number;
}