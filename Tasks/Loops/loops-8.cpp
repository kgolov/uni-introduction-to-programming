#include <iostream>

using namespace std;

int main() {
	int n = 1;
	cout << "Enter a number N: ";
	cin >> n;
	cout << endl;

	cout << "Prime numbers smaller than " << n << " are:" << endl;

	for (int i = 1; i < n; i++) {
		// need to check if i is prime
		bool iIsPrime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) iIsPrime = false;
		}

		if (iIsPrime) cout << i << endl;
	}

	cout << endl;

	return 0;
}