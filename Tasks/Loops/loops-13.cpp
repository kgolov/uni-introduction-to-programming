#include <iostream>

using namespace std;

int main() {
	int n = 1;
	cout << "Enter an odd number: ";
	cin >> n;
	cout << endl;

	if (n % 2 == 0 || n < 1) {
		cout << "Error!" << endl;
		return 0;
	}

	// TOP PART
	int rows = (n + 1) / 2;
	int stars = 1;
	for (int row = 1; row <= rows; row++) {
		// print white spaces
		for (int i = 1; i <= (n - stars) / 2; i++) {
			cout << ' ';
		}
		// print stars
		for (int j = 1; j <= stars; j++) {
			cout << '*';
		}
		// print white spaces
		for (int s = 1; s <= (n - stars + 1); s++) {
			cout << ' ';
		}
		// print stars
		for (int j = 1; j <= stars; j++) {
			cout << '*';
		}
		stars += 2;
		cout << endl;
	}

	// BOTTOM PART
	stars = 2 * n - 1;
	for (; stars >= 1; stars -= 2) {
		// print white spaces
		for (int i = 1; i <= (2 * n + 1 - stars) / 2; i++) {
			cout << ' ';
		}
		// print stars
		for (int j = 1; j <= stars; j++) {
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}