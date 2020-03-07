#include <iostream>
#include "Revert.h"

int main() {
	char test[] = "Hello!";

	Revert(test);

	std::cout << test << std::endl;

	return 0;
}