#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;
	cout << endl;

	
	for (int row = 0; row < n; row++) {
		for (int col = 1; col <= n; col++) {
			cout << left << setw(3) << row * n + col;
		}
		cout << endl;
	}

	return 0;
}