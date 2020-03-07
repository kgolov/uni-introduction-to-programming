#include <iostream>

using namespace std;

int main() {
	int n = 1;
	cout << "Enter an odd number: ";
	cin >> n;
	cout << endl;

	if (n % 2 == 0 || n < 1) {
		cout << "Error! Your number is not odd.";
		return 0;
	}

	int lines = (n + 1) / 2;
	int stars = 1;
	for (int row = 1; row <= lines; row++) {
		// print white spaces
		for (int i = 1; i <= (n - stars) / 2; i++) {
			cout << ' ';
		}
		// print stars
		for (int j = 1; j <= stars; j++) {
			cout << '*';
		}
		stars += 2;
		cout << endl;
	}

	// print base of tree
	for (int i = 1; i <= (n - 1) / 2; i++) {
		cout << ' ';
	}
	cout << '*' << endl << endl;

	return 0;
}