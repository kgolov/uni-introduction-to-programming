#include <iostream>

using namespace std;

int main() {
	int day = 0, month = 0, year = 0;
	cout << "Enter a date in the following format: DD MM YYYY" << endl;
	cin >> day >> month >> year;

	if (day < 1 || month < 1 || month > 12 || year < 1900) {
		cout << "Invalid!" << endl;
		return 0;
	} 
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31) {
				cout << "Invalid!" << endl;
				return 0;
			}
		case 4: case 6: case 9: case 11:
			if (day > 30) {
				cout << "Invalid!" << endl;
				return 0;
			}
		case 2:
			// calculate if year is leap
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				// year is leap
				if (day > 29) {
					cout << "Invalid!" << endl; 
					return 0;
				}
			}
			else {
				// year is not leap
				if (day > 28) {
					cout << "Invalid!" << endl;
					return 0;
				}
			}
	}

	cout << "Valid!" << endl;

	return 0;
}