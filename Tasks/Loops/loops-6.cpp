#include <iostream>

using namespace std;

int main() {
	int number = 0;
	cout << "Enter a number less than 10 000:" << endl;
	cin >> number;
	cout << endl;

	if (number < 1 || number > 9999) {
		cout << "Cannot convert your number!" << endl << endl;
		return 0;
	}

	char first, second, third;

	cout << "Your number in Roman numerals is:" << endl;
	
	int numLength = (int)log10(number);
	for (; numLength >= 0; numLength--) {
		int currentDigit = number / (int)pow(10, numLength);
		number %= (int)pow(10, numLength);
		if (numLength == 3) {
			for (int i = 0; i < currentDigit; i++) {
				cout << 'M';
			}
			continue;
		}
		switch (numLength) {
			case 0:
				first = 'I';
				second = 'V';
				third = 'X';
				break;
			case 1:
				first = 'X';
				second = 'L';
				third = 'C';
				break;
			case 2:
				first = 'C';
				second = 'D';
				third = 'M';
				break;
		}

		switch (currentDigit) {
			case 1:
				cout << first;
				break;
			case 2: 
				cout << first << first;
				break;
			case 3:
				cout << first << first << first;
				break;
			case 4:
				cout << first << second;
				break;
			case 5:
				cout << second;
				break;
			case 6:
				cout << second << first;
				break;
			case 7: 
				cout << second << first << first;
				break;
			case 8:
				cout << second << first << first << first;
				break;
			case 9: 
				cout << first << third;
				break;
		}
	}

	cout << endl;

	return 0;
}