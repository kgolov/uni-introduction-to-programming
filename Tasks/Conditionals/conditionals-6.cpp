#include <iostream> 

using namespace std;

int main() {
	int dayOne = 0, monthOne = 0, dayTwo = 0, monthTwo = 0;
	cout << "Enter two days in the following format: DD MM DD MM" << endl;
	cin >> dayOne >> monthOne >> dayTwo >> monthTwo;

	if (dayOne < 1 || monthOne < 1 || dayTwo < 1 || monthTwo < 1 || monthOne > monthTwo) return 0;

	int daysTotal1 = 0, daysTotal2 = 0;

	switch (monthOne) {
		case 12:
			daysTotal1 += 30;
		case 11:
			daysTotal1 += 31;
		case 10: 
			daysTotal1 += 30;
		case 9:
			daysTotal1 += 31;
		case 8:
			daysTotal1 += 31;
		case 7:
			daysTotal1 += 30;
		case 6:
			daysTotal1 += 31;
		case 5:
			daysTotal1 += 30;
		case 4:
			daysTotal1 += 31;
		case 3:
			daysTotal1 += 28;
		case 2:
			daysTotal1 += 31;
		case 1:
			daysTotal1 += dayOne;
			break;
		default: return 0;
	}
	switch (monthTwo) {
		case 12:
			daysTotal2 += 30;
		case 11:
			daysTotal2 += 31;
		case 10:
			daysTotal2 += 30;
		case 9:
			daysTotal2 += 31;
		case 8:
			daysTotal2 += 31;
		case 7:
			daysTotal2 += 30;
		case 6:
			daysTotal2 += 31;
		case 5:
			daysTotal2 += 30;
		case 4:
			daysTotal2 += 31;
		case 3:
			daysTotal2 += 28;
		case 2:
			daysTotal2 += 31;
		case 1:
			daysTotal2 += dayTwo;
			break;
		default: return 0;
	}

	int difference = daysTotal2 - daysTotal1;
	cout << difference << endl;

	return 0;
}