#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Enter the three sides of a triangle: ";
	cin >> a >> b >> c;

	// sort the three sides of the triangle
	int temp = 0;
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	} 
	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}

	if ((a * a + b * b) == c * c) {
		cout << "The triangle is right." << endl;
	}
	else if ((a * a + b * b) < c * c) {
		cout << "The triangle is obtuse." << endl;
	}
	else {
		cout << "The triangle is acute." << endl;
	}

	return 0;
}