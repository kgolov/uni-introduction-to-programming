#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cout << "Enter how many Fibonacci numbers you wish: ";
	cin >> n;
	cout << endl;
	int num1 = 1, num2 = 1;

	if (n < 1) return 0;

	if (n == 1) {
		cout << num1 << endl;
	}
	else {
		cout << num1 << endl;
		cout << num2 << endl;
	}
	for (int i = 3; i <= n; i++) {
		int nextFibonacci = num1 + num2;
		cout << nextFibonacci << endl;
		num1 = num2;
		num2 = nextFibonacci;
	}

	return 0;
}