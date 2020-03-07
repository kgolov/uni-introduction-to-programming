#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cout << "Enter a number n: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			cout << "Fizz";
		}
		if (i % 5 == 0) {
			cout << "Buzz";
		}
		if (i % 3 != 0 && i % 5 != 0) {
			cout << i;
		}
		cout << endl;
	}

	return 0;
}