#include <iostream>

using namespace std;

int main() {
	int points = 0;
	cout << "How many points have you scored on the Calculus exam?" << endl;
	cin >> points;

	if (points >= 0 && points <= 20) {
		cout << "2! Please try again in September" << endl;
	}
	else if (points > 20 && points <= 40) {
		cout << "3! Whew, that was a close one" << endl;
	}
	else if (points > 40 && points <= 60) {
		cout << "4! Not much I can say, you are just a regular fellow" << endl;
	}
	else if (points > 60 && points <= 80) {
		cout << "5! If only you didn't go drinking the night before the exam..." << endl;
	}
	else if (points > 80 && points <= 100) {
		cout << "6! There's no way you did this by yourself, how did you cheat?" << endl;
	}
	
	return 0;
}