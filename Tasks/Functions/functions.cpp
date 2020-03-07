#include <iostream>

// Task 1
int sum(int a, int b) {
	return a + b;
}

// Task 2
int abs(int a) {
	return (a < 0) ? -a : a;
}

// Task 3
int greaterOfTwo(int a, int b) {
	return (a >= b) ? a : b;
}

// Task 4
bool areEqual(int a, int b) {
	return a == b;
}

// Task 5
bool isWithinDistance(int a, int b, int epsilon) {
	return (abs(a - b) < abs(epsilon));
}

// Task 6
int power(int number = 1, int power = 0) {
	int result = number;
	for (int i = 1; i <= power; i++) {
		result *= number;
	}
	return result;
}

// Task 7
int reverseNumber(int number) {
	int newNumber = 0, currentDigit = 0;
	while (number) {
		currentDigit = number % 10;
		newNumber += currentDigit;
		newNumber *= 10;
		number /= 10;
	}
	newNumber /= 10;
	return newNumber;
}

// Task 8
int min(int a, int b, int c) {
	int min = a;
	if (b < min) {
		min = b;
	} 
	if (c < min) {
		min = c;
	}
	return min;
}

// Task 9
int isPrime(int n) {
	if (n == 1 || n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	bool isPrime = true;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			isPrime = false;
		}
	}
	return isPrime;
}

// Task 10
bool smallestPrime(int a, int b, int c) {
	return isPrime(min(a, b, c));
}

// Task 11
bool isDigit(char c) {
	return (c > 47 && c < 58);
}

// Task 12
bool isLetter(char c) {
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

// Task 13
bool bothTrue(bool a, bool b) {
	return a && b;
}

// Task 14
bool isDivisible(int first, int second) {
	if (second == 0) return false; 
	else {
		return !(first % second);
	}
}

// Task 15
int sum_of_N_numbers(int n) {
	return (n * (n + 1)) / 2;
}

// Task 16
double rootOfLinearEquation(double a, double b) {
	// return 0 if a == 0 because we cannot indicate in another way
	// that there are no roots or there are many roots
	if (a == 0) return 0;
	return (-1) * (b / a);
}

// Task 17
double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
	double result = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	return sqrt(result);
}

int main() {
	double a, b;
	std::cin >> a >> b;
	std::cout << rootOfLinearEquation(a, b);
	return 0;
}