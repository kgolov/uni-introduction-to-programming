#pragma once

bool doExist(const char* symbols, const char* word) {
	if (symbols == nullptr || word == nullptr) {
		return false;
	}

	bool flag = false;

	int secondIndex = 0;
	for (int firstIndex = 0; symbols[firstIndex] != '\0'; firstIndex++) {
		if (symbols[firstIndex] == word[secondIndex]) {
			// The first letters are the same, save the current first index as temp because
			// we may need to revert to it.
			int temp = firstIndex;
			
			while (symbols[firstIndex] == word[secondIndex] && word[secondIndex] != '\0') {
				// Increment both indexes
				firstIndex++;
				secondIndex++;
			}

			if (word[secondIndex] == '\0') {
				// If we have reached a terminating zero, we have found the whole word in the symbols string
				flag = true;
				secondIndex = 0;
				firstIndex--;
			}
			else {
				// Else, we haven't found the whole word, revert back to the original indexes
				firstIndex = temp;
				secondIndex = 0;
			}
		}
	}

	return flag;
}