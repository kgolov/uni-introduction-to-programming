#include <iostream>

char* secondsToHours(int seconds) {
	if (seconds < 0 || seconds > 86000) {
		return nullptr;
	}

	int hours = seconds / 3600;
	int minutes = (seconds % 3600) / 60;

	char* correctFormat = new char[6];
	correctFormat[0] = (hours / 10) + '0';
	correctFormat[1] = (hours % 10) + '0';
	correctFormat[2] = ':';
	correctFormat[3] = (minutes / 10) + '0';
	correctFormat[4] = (minutes % 10) + '0';
	correctFormat[5] = '\0';

	return correctFormat;
}

int main() {
	int seconds = 0;
	std::cin >> seconds;

	if (seconds < 0 || seconds > 86000) {
		std::cout << "Error!" << std::endl;
	}

	char* time = secondsToHours(seconds);
	std::cout << time << std::endl;

	delete[] time;
	return 0;
}