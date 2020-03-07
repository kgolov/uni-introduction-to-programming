/**
*
* Solution to homework task 3
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

using namespace std;

int main() {
	// Set constants for our lower and upper bound numbers
	const int lowerBound = 0;
	const int upperBound = 15;
	// Initialize variables to store our inputs and result later
	int number1 = 0, number2 = 0, operation = 0, result = 0;

	// Input three numbers from the console
	cin >> number1 >> number2 >> operation;
	// If the input failed or the numbers are out of range, output "Wrong input" and terminate the program
	if (cin.fail() ||
		number1 < lowerBound || number1 > upperBound ||
		number2 < lowerBound || number2 > upperBound)
	{
		cout << "Wrong input" << endl;
		return 0;
	}

	// Examine possible operations
	if (operation == 0) {
		// We need to add the numbers
		result = number1 + number2;
	}
	else if (operation == 1) {
		// We need to subtract the numbers
		result = number1 - number2;
	}
	else if (operation == 2) {
		// We need to multiply the numbers
		result = number1 * number2;
	}
	else if (operation == 3 && number2 != 0) {
		// We need to divide the numbers, only if the second one is not zero
		result = number1 / number2;
	}
	else {
		// Else (if the operation is not 0-3 or we attempt to divide to zero),
		// we throw the error "Wrong input" and terminate the program
		cout << "Wrong input" << endl;
		return 0;
	}

	while (result > upperBound) {
		// If we are in this loop, the result overflowed
		// We need to keep subtracting from it until we finally remain in the allowed range
		result -= upperBound - lowerBound + 1;
	}
	while (result < lowerBound) {
		// If we are in this loop, the result underflowed
		// We need to keep adding to it until we finally remain in the allowed range
		result += upperBound - lowerBound + 1;
	}
	
	// The number is now in the allowable range, output it on the console
	cout << result << endl;

	// End the program
	return 0;
}