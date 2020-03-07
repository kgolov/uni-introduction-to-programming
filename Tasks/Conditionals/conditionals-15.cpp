#include <iostream>

using namespace std;

int main() {
	char c;
	cout << "Enter a character: ";
	cin >> c;

	// convert the character to its ASCII represented decimal code
	int charCode = (int)c;

	if (charCode > 47 && charCode < 58) {
		// the character is a digit
		cout << "digit" << endl;
	}
	else if ((charCode > 64 && charCode < 91) ||
			(charCode > 96 && charCode < 123)) {
		// the character is a letter
		cout << "letter" << endl;
	}
	else {
		// the character is a special character
		cout << "special char" << endl;
	}

	return 0;
}