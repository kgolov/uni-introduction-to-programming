#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0, p = 0, q = 0;
	cout << "Enter the parameters of the quadratic function and the range wanted: " << endl;
	cin >> a >> b >> c >> p >> q;

	// make sure p<q
	if (p > q) {
		int temp = q;
		q = p;
		p = temp;
	}

	double fMax = 0;
	double xMax = 0;

	// analyze a and xV
	if (a == 0) {
		// the function becomes linear
		// the maximum value of the function is in either p or q
		int fp = a * p * p + b * p + c;
		int fq = a * q * q + b * q + c;
		if (fp > fq) {
			fMax = fp;
			xMax = p;
		}
		else {
			fMax = fq;
			xMax = q;
		}
	}
	else {
		// calculate xV
		double xV = -b / 2 * (double)a;

		if ((a > 0) || (a < 0 && (xV < p || xV > q))) {
			// the maximum value of the function is in either p or q
			int fp = a * p * p + b * p + c;
			int fq = a * q * q + b * q + c;
			if (fp > fq) {
				fMax = fp;
				xMax = p;
			}
			else {
				fMax = fq;
				xMax = q;
			}
		}
		else {
			// the maximum value is xV
			fMax = a * xV * xV + b * xV + c;
			xMax = xV;
		}
	}

	cout << "The maximum value of the function is " << fMax << " when x = " << xMax << endl;

	return 0;
}