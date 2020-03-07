#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cout << "Enter the three sides of a triangle: ";
	cin >> a >> b >> c;

	if (a < 1 || b < 1 || c < 1) return 0;

	if ((a + b) >= c && (a + c) >= b && (b + c) >= a) {
		cout << "Such a triangle exists." << endl;
	}
	else {
		cout << "Such a triangle does not exist." << endl;
	}

	return 0;
}