#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n = 0;
	cout << "Enter a number N: ";
	cin >> n;
	cout << endl;

	int number = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << left << setw(3) << number++;
		}
		cout << endl;
	}

	return 0;
}