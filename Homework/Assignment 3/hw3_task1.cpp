/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Kiril Golov
* @idnumber 62360
* @task 1
* @compiler VC
*
*/


#include <iostream>
#include <thread>
#include <chrono>

const int rows = 5;		  // Defines how many rows the ASCII art picture will have
const int cols = 39;	  // Defines how many columns the ASCII art picture will have
const int maxHeight = 25; // Defines the height of the console
const int maxWidth  = 80; // Defines the width of the console

// Defines how many empty rows need to be printed in order to center the text vertically
const int emptyRows = (maxHeight - rows) / 2;

// Appends a character to a given string
void charAppend(char* destination, const char source) {
	if (destination == nullptr) {
		return;
	}

	// Find the index of the terminating zero (end of string)
	int i;
	for (i = 0; destination[i] != '\0'; i++) {

	}

	// Add the character and then another terminating zero
	destination[i] = source;
	destination[i + 1] = '\0';
}

// Draws the desired ASCII art word on the screen and animates it moving from left to right
// Has cols + 1 characters to accommodate the terminating 0 at the end of each string (row).
// Later in the code, it is discarded and not shown.
void drawText(const char const text[rows][cols + 1]) {
	if (text == nullptr) {
		return;
	}

	// A buffer string which will hold all the text for the output,  before flushing it all at once.
	char buffer[maxHeight * (maxWidth + 1)];
	// We are adding 1 to maxWidth to accommodate the end of line character at each line (theoretical maximum)
	/*
	DISCLAIMER:
		I do not claim that this approach is more efficient or faster than using cout multiple times.
		It is just the simplest thing to do to remove the flickering that comes when doing that,
		without overcomplicating the code or using external libraries.
		After all, speed is not critical here.
	*/

	int colsVisible = 1; // The number of columns of the picture which will be visible at any moment
	int whitespaces = 0; // The number of whitespaces added before the picture to move it right
	bool startedDisappearing = false; // Has the text started disappearing to the right?

	// The main loop which will continue until the text has come out, moved to the right and then disappeared.
	while (colsVisible >= 0) {
		// Clear the console.
		system("CLS");
		// Set the first character of the buffer screen to \0, effectively 'clearing' it
		// (not really, but it will be overwritten)
		buffer[0] = '\0';

		// To center the picture vertically - add to the buffer emptyRows number of new lines.
		for (int row = 0; row < emptyRows; row++) {
			charAppend(buffer, '\n');
		}

		// Begin drawing by getting each line of the picture
		for (int row = 0; row < rows; row++) {
			// Add to the buffer a whitespace number of spaces
			// (In the beginning zero, until the text has fully appeared, then slowly increasing)
			for (int space = 0; space < whitespaces; space++) {
				charAppend(buffer, ' ');
			}

			// Initialize a col counter for the below loop, it starts differently depending on whether
			// the text is appearing and moving, or disappearing.
			int col;
			if (startedDisappearing) {
				// If the text has started disappearing, always start from the beginning
				col = 0;
			}
			else {
				// Else, start from the column calculated below.
				col = cols - colsVisible;
			}

			// A loop to go through each column of the picture. It has different conditions depending on whether
			// the text has started to disappear or not.
			while ( (!startedDisappearing && col < cols) ||
					(startedDisappearing &&  col < colsVisible)) {
				// Append the current character to the buffer string.
				charAppend(buffer, text[row][col]);
				// Increment our counter.
				col++;
			}

			// Append a new line to buffer.
			charAppend(buffer, '\n');
		}

		// Change of variables
		// If the text has not started disappearing, and the visible columns are not yet all, increment them
		if (!startedDisappearing && colsVisible < cols) {
			colsVisible++;
		}
		else {
			// Else, the text has fully appeared and we need to add whitespaces.
			whitespaces++;
		}

		// If we have started disappearing, decrement the number of columns visible.
		if (startedDisappearing) {
			colsVisible--;
		}
		// Check if the text needs to start disappearing, i.e. have the number of columns of the picture
		// and the number of whitespaces reached the maximum width of the console.
		if (whitespaces + cols == maxWidth) {
			startedDisappearing = true;
		} 		

		// Push all the text from the buffer to the console.
		/*
		DISCLAIMER:
			I do not claim that this approach is more efficient or faster than using cout multiple times.
			It is just the simplest thing to do to remove the flickering that comes when doing that,
			without overcomplicating the code or using external libraries.
			After all, speed is not critical here.
		*/
		std::cout << buffer << std::flush;
		// Add a 75 millisecond delay to animate the text motion.
		std::this_thread::sleep_for(std::chrono::milliseconds(75));
	}

	// End our function.
}

int main() {
	// Declare a two-dimensional array, which contains our ASCII art picture to move,
	// with rows and columns of characters respectively.
	// The array has cols + 1 characters, to accommodate the terminating 0 at the end of each string (row).
	const char text[rows][cols + 1] = 
							{  "H   H   EEEEE   L       L          O   ",
							   "H   H   E       L       L        O   O ",
							   "HHHHH   EEEEE   L       L       O     O",
							   "H   H   E       L       L        O   O ",
							   "H   H   EEEEE   LLLLL   LLLLL      O   "   };

	// Put a deliberate infinte loop in order to animate the text infinitely.
	while (true) {
		// Animate the text with our written function.
		drawText(text);
	}

	// End the program
	return 0;
}