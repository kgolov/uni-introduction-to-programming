#include <iostream>
#include "doExist.h"

int main() {
	std::cout << doExist("abcdefg", "def") << std::endl; // returns true, because def is found in abcdefg
	std::cout << doExist("abcdefg", "deg") << std::endl; // returns false, because the last letter does not match
	std::cout << doExist("abcdefdeg", "deg") << std::endl; // returns true

	return 0;
}