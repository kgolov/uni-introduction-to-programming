/**
*
* Solution to homework task 2
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

using namespace std;

// Declaring a function which will be reading from the console and validating the input
long long safelyInputNumber(long long lowerBound = -4294967296LL, long long upperBound = 4294967295LL);
// The default parameters come from the task - it says that it should accept numbers in
// the interval [-2^32 ; 2^32 - 1]. A usual long int is not enough in this case, because it accepts numbers
// from -2^31 to 2^31-1.

int main() {
	// Input a number and a digit for which to search
	long long number = safelyInputNumber();
	int digit = safelyInputNumber(0, 9);
	// Get the absolute value of our number - we want to work only with positive numbers for our
	// algorithm to work (we won't impact the final result)
	number = (number >= 0) ? number : -number;

	// Initialize a variable to store the number of occurences of the digit in the number
	int occurences = 0;

	// A loop which checks how many times the digit is in the number
	do {
		int currentDigit = number % 10;
		if (digit == currentDigit) {
			// If the digit is in the number, we add one to the number of occurences.
			occurences++;
		}
		number /= 10;
	} while (number);
	/* BONUS FACT
		The use of the do-while loop here is necessary for the program to be able to 
		output 1 occurence when the number is 0, and the digit is also 0.
		This way, we always enter the loop at least once, compared to other types of loops.	*/

	// Output the number of occurences 
	cout << occurences << endl;

	// End of program
	return 0;
}


/* A function to safely input a number within any range of integers, or a strictly specified one */
long long safelyInputNumber(long long lowerBound, long long upperBound) {
	long long number;

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