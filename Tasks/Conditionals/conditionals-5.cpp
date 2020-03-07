#include <iostream>

using namespace std;

int main() {
	int command = 0;
	cout << "Enter a command: ";
	cin >> command;

	if (command == 1) {
		int a = 0, b = 0;
		cout << "Enter two numbers to add: " << endl;
		cin >> a >> b;

		cout << "Their sum is: " << a + b << endl;
	}
	else if (command == 2) {
		int a = 1, b = 1;
		cout << "Enter two numbers to multiply: " << endl;
		cin >> a >> b;

		cout << "Their multiple is: " << a * b << endl;
	}
	else if (command == 3) {
		int number = 1, power = 1, result = 1;
		cout << "Enter a number and the desired power: " << endl;
		cin >> number >> power;

		for (int i = 1; i <= power; i++) {
			result *= number;
		} 

		cout << number << " to the power of " << power << " is " << result << endl;
	}

	return 0;
}