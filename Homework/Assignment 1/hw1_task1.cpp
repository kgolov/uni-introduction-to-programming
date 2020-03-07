/**
*
* Solution to homework task 1
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

using namespace std;

// Declaring a function which will be reading from the console and validating the input
int safelyInputNumber(int lowerBound = -65536, int upperBound = 65535);
// The default parameters come from the task - it says that it should accept numbers up to 2^16

int main() {
	// Initialize three variables to hold our needed data
	int lastNumber = 0;
	int minNumber = 0;
	int maxNumber = 0;

	/* A loop which enters a number continuously using the function safelyInputNumber(),
	   checks it a number of times and stops if the entered number is negative. */
	while ((lastNumber = safelyInputNumber()) >= 0) {
		if (lastNumber == 0) {
			// If the entered number was zero, we do nothing and prompt the user to enter a number again
			continue;
		}
		// Else, the number was positive.

		// We need to check if we have saved any values yet. 
		if (minNumber == 0 && maxNumber == 0) {
			// This is our first number. We save it as a minNumber, and later we will check it against the next.
			minNumber = lastNumber;
		}
		else if (maxNumber == 0 && minNumber != 0) {
			// This is our second number. We check:
			// If it is smaller than the first, we save it as a minNumber and save the first as a maxNumber.
			if (lastNumber < minNumber) {
				maxNumber = minNumber;
				minNumber = lastNumber;
			}
			// If it is bigger or equal to the first, we save it as a maxNumber.
			else {
				maxNumber = lastNumber;
			}
		} 
		else {
			// We are in our third, fourth, etc. loop. We only need to check if our number
			// is bigger than our maxNumber or smaller than our minNumber.
			if (lastNumber < minNumber) {
				minNumber = lastNumber;
			}
			if (lastNumber > maxNumber) {
				maxNumber = lastNumber;
			}
		}
	}

	// We are now out of the loop. We want to check if we have entered at least two values.
	if (minNumber != 0 && maxNumber != 0) {
		// We have entered at least two values. We can easily subtract them and show the user the result.
		cout << (maxNumber - minNumber) << endl;
	}
	else {
		// We have not entered at least two valid values. We need to output "Error" as per the task
		// (and what the lecturer said).
		cout << "Error" << endl;
	}

	// End of our program
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