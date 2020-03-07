#include <iostream>

using namespace std;

int main() {
	int number = 0;
	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	if (number < 1) return 0;
	bool isPrime = true;

	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) isPrime = false;
	}

	cout << number << ((isPrime) ? " is " : " is not ") << "prime" << endl << endl;

	return 0;
}