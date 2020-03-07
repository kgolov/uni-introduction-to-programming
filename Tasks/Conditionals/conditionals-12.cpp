#include <iostream>

using namespace std;

int main() {
	double x = 0; double y = 0;
	cout << "Enter the coordinates of a 2D point: " << endl;
	cin >> x >> y;
	
	if (x < 0 || x > 1 || y < 0 || y > 1) {
		cout << "The point is not in the unit square." << endl;
	}
	else {
		cout << "The point is in the unit square." << endl;
	} 

	if (x * x + y * y > 1) {
		cout << "The point is not in the unit circle." << endl;
	}
	else {
		cout << "The point is in the unit circle." << endl;
	}

	return 0;
}