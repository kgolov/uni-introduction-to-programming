#include <iostream>

using namespace std;

int main() {
	long long number = 0;
	cout << "Enter a number: ";
	cin >> number;
	cout << endl;
	
	int length = 1;
	long long number2 = number;
	while (number2 /= 10) length++;

	long long newNumber = 0;

	do {
		length--;
		newNumber += (number % 10) * pow(10, length);
		number /= 10;
	} while (number != 0);

	cout << newNumber << endl;

	return 0;
}