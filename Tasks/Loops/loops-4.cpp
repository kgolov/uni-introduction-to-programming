#include <iostream>

using namespace std;

int main() {
	int n = 0, input = 0;
	cout << "Enter a number n: ";
	cin >> n;
	cout << endl;

	int sum = 0;

	cout << "Enter " << n << " more numbers:" << endl;
	for (int i = 0; i < n; i++) {
	input = 0;
		cin >> input;
		sum += input;
	}

	cout << endl << "The sum of all numbers is: " << sum << endl << endl;

	return 0;
}