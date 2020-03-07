#include <iostream>

using namespace std;

int main() {
	int number = 0;
	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	if (number < 1) return 0;
	if (number == 1) cout << "1";

	for (int i = 2; i <= number; i++) {
		// need to check if i is prime
		bool iIsPrime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) iIsPrime = false;
		}

		if (iIsPrime) {
			while (number % i == 0) {
				cout << i << '.';
				number /= i;
			}
		}
	}

	cout << '\b';
	cout << ' ';
	cout << endl;
	return 0;
}