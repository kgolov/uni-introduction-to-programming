#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int max = 0;
	cout << "Enter five numbers: ";
	cin >> a >> b >> c >> d >> e;

	if (a >= b && a >= c && a >= d && a >= e) max = a;
	if (b >= a && b >= c && b >= d && b >= e) max = b;
	if (c >= a && c >= b && c >= d && c >= e) max = c;
	if (d >= a && d >= b && d >= c && d >= e) max = d;
	if (e >= a && e >= b && e >= c && e >= d) max = e;

	cout << "The biggest number is: " << max << endl;

	return 0;
}