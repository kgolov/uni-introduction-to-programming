#include <iostream>
#include "checkDate.h"

int main() {
	std::cout << checkDate("11.01") << std::endl; // true, because it is valid
	std::cout << checkDate("00.12") << std::endl; // false, because the day is 0
	std::cout << checkDate("30.02") << std::endl; // false, because the day is 30 and the month is February
	std::cout << checkDate("22:11") << std::endl; // false, because we have a ':' instead of a dot '.'
	std::cout << checkDate("a3.07") << std::endl; // false, because we have another character and not a number
	std::cout << checkDate("12.15") << std::endl; // false, because the month is 15
	std::cout << checkDate("32.10") << std::endl; // false, because the day is 32

	return 0;
}