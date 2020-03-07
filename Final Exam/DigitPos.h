#pragma once

int DigitPos(long num, int k) {
	int result = -1;

	if (k < 0) {
		return result;
	}

	long temp = num;
	int digits = 0;

	do {
		temp /= 10;
		digits++;
	} while (temp);

	if (k > digits) {
		return result;
	}

	for (int i = digits - k; i > 0; i--) {
		num /= 10;
	}

	result = num % 10;

	return result;
}