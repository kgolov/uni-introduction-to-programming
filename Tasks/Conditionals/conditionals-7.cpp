#include <iostream>

using namespace std;

int main() {
	int month = 0;
	cout << "Enter a month (number from 1 to 12): ";
	cin >> month;
	int days = 0;

	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			days = 31; 
			break;
		case 4: case 6: case 9: case 11:
			days = 30;
			break;
		case 2: 
			days = 29;
			break;
		default: 
			cout << "There is no such month!" << endl;
			return 0;
	}

	cout << "There are " << days << " days in this month." << endl;

	return 0;
}