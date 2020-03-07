bool checkDate(const char* date) {
	if (date == nullptr) {
		return false;
	}

	bool flag = true;

	// Firstly, check if the first two characters are numbers, the third - a dot, and the fourth
	// and fifth - also numbers.
	for (int i = 0; date[i] != '\0'; i++) {
		if (i == 0 || i == 1 || i == 3 || i == 4) {
			if (date[i] < '0' || date[i] > '9') {
				flag = false;
			}
		}

		if (i == 2) {
			if (date[i] != '.') {
				flag = false;
			}
		}
	}

	// If we have failed here, stop already
	if (!flag) {
		return flag;
	}
	
	// Then, check if the day and month are valid. Firstly, convert them to numerical
	int firstDay = date[0] - '0';
	int secondDay = date[1] - '0';
	int day = firstDay * 10 + secondDay;

	int firstMonth = date[3] - '0';
	int secondMonth = date[4] - '0';
	int month = firstMonth * 10 + secondMonth;

	if (month < 1 || month > 12 || day < 1 || day > 31) {
		flag = false;

		// Stop already
		return flag;
	}

	// Check against how many days a month has
	switch (month) {
		case 2: 
			if (day > 28) {
				flag = false;
			}
		
		case 4: case 6: case 9: case 11:
			if (day > 30) {
				flag = false;
			}
	}

	// Finally return the flag
	return flag;
}