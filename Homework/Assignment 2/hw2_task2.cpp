/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 2
* @compiler VC
*
*/

#include <iostream>

/* Returns the starting index of the longest repetition of needle in haystack */
int searchInString(const char* haystack, const char* needle) {
	if (haystack == nullptr || needle == nullptr) {
		return -2;
	}

	// Initialize variables to store:
	// The current starting index of the found repetitions of needle in haystack
	int currentIndex = 0;
	// The current length of the checked repetitions
	int currentLength = 0;
	// The starting index of the longest repetition
	int maxIndex = 0;
	// The length of the longest repetition
	int maxLength = 0;

	// A loop to check every character of the first string
	for (int firstIndex = 0; haystack[firstIndex] != '\0'; firstIndex++) {
		// An index to go through the second string
		int secondIndex = 0;

		// If this condition is true, then we have found the first letter of the second string
		if (haystack[firstIndex] == needle[secondIndex]) {
			// If we are not already in a succession of repetitions, 
			// save the currentIndex and set the currentLength to 0.
			if (firstIndex != currentIndex + currentLength) {
				currentIndex = firstIndex;
				currentLength = 0;
			}

			// Also save the current Index of the first string, in case we do not find the whole second one,
			// we will need to revert to it.
			int temp = firstIndex;

			// A while loop to loop through every character in the second string, until we 
			// either find the whole part of it or not.
			// Also, increment the currentLength.
			while (haystack[firstIndex] == needle[secondIndex] && needle[secondIndex] != '\0') {
				currentLength++;
				firstIndex++;
				secondIndex++;
			}

			if (needle[secondIndex] == '\0') {
				// We have found the whole second string 

				// If the currentLength of the succession is bigger than the maximum one at the moment, 
				// save the currentLength and Index as the maximum ones.
				if (currentLength > maxLength) {
					maxLength = currentLength;
					maxIndex = currentIndex;
				}

				// Decrement firstIndex by one, because it was last incremented,
				// and otherwise we will skip one character.
				firstIndex--;

				// Start the loop again, looking for more repetitions.
				// continue;
			}
			else {
				// We have not found the whole second string, only a part of it
				// This does not count, so revert to the last Index, reset the current Length 
				firstIndex = temp;
				currentLength = 0;
				// Continue with the loop, looking for more matches.
				// continue;
			}
		}
	}

	// After this for loop, we have found the starting index and the length of the maximum
	// amount of repetitions of the second string in the first one.

	// If they are both zero, this means that the second string was not found at all.
	if (maxIndex == 0 && maxLength == 0) {
		// Set maxIndex to -1 to indicate that the string was not found.
		maxIndex = -1;
	}

	// Return the index that the longest repetition was found.
	return maxIndex;
}

/* Returns the length of the longest repetition of needle in haystack */
int lengthOfRepetition(const char* haystack, const char* needle) {
	if (haystack == nullptr || needle == nullptr) {
		return -2;
	}

	// Get the starting index of the longest repetition
	int startingIndex = searchInString(haystack, needle);

	// Check if a repetition is found at all
	if (startingIndex < 0) {
		// A repetition is not found, return a length of zero
		return 0;
	}
	
	// Variables to store the length of the repetition
	// Firstly, the one that is confirmed and we will return in the end of the function
	int maxLength = 0;
	// And then, one to work with locally and is possible to contain false information
	// (if we find only a part of the second string, but not it as a whole)
	int currentLength = 0;
	// A variable to store the index of the second string
	int secondIndex = 0;

	// A loop to go through the first string
	while (haystack[startingIndex] != '\0') {
		// A loop which looks to find identical characters in the two strings
		while (haystack[startingIndex] == needle[secondIndex] && needle[secondIndex] != '\0') {
			// Increment the current Length and both indexes
			currentLength++;
			startingIndex++;
			secondIndex++;
		}

		// If this statement is true, we have reached the end of the second string.
		if (needle[secondIndex] == '\0') {
			// Reset the index of the second string
			secondIndex = 0;
			// Record the current length as the maximum confirmed one.
			maxLength = currentLength;
		}
		else {
			// If at the end of the previous loop, we are not at the end of the second string,
			// this means that we have found only a part of it. Stop the main loop, because
			// the repetition is stopped.
			break;
		}
	}

	// At the end of this loop, we have received the length of the longest succession of repetitions
	return maxLength;
}

int main() {
	// Declare a constant max size of our strings
	const int MAX_SIZE = 100;
	// Declare strings
	char B[MAX_SIZE];
	char C[MAX_SIZE];
	// Input strings one after the other.
	std::cout << "Input a string to search in: "; 
	std::cin >> B;
	std::cout << "Input a string to search for: ";
	std::cin >> C;

	// Use our written functions with the entered strings B and C.
	int startingIndex = searchInString(B, C);
	int length = lengthOfRepetition(B, C);

	// Print the needed information
	std::cout << std::endl;
	std::cout << "Index: " << startingIndex << std::endl;
	std::cout << "Length: " << length << std::endl;

	// End program
	return 0;
}