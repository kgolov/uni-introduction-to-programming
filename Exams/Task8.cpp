#include <iostream>

double absolute(const double number) {
	return (number >= 0) ? number : -number;
}

struct line {
	double Ax;
	double Ay;
	double Bx;
	double By;
	double length = 0;
};

double mutualPart(line first, line second) {
	double mutual = -1;

	if (first.Ax == first.Bx && first.Bx == second.Ax && second.Ax == second.Bx) {
		// They lie on a line parallel to the Y-axis

		// Calculate the length of every line
		first.length = absolute(first.Ay - first.By);
		second.length = absolute(second.Ay - second.By);
		
		// Calculate the upmost and downmost point on the coordinate system to calculate the 
		// length of the combined lines
		double minY = first.Ay;
		if (first.By < minY) {
			minY = first.By;
		}
		if (second.Ay < minY) {
			minY = second.Ay;
		}
		if (second.By < minY) {
			minY = second.By;
		}

		double maxY = first.Ay;
		if (first.By > maxY) {
			maxY = first.By;
		}
		if (second.Ay > maxY) {
			maxY = second.Ay;
		}
		if (second.By > maxY) {
			maxY = second.By;
		}

		// Calculate the length of the combined lines
		double combined = absolute(maxY - minY);

		// Calculate the length of the mutual part
		mutual = (first.length + second.length) - combined;
	}
	else if (first.Ay == first.By && first.By == second.Ay && second.Ay == second.Bx) {
		// They lie on a line parallel to the X-axis

		// Calculate the length of every line
		first.length = absolute(first.Ax - first.Bx);
		second.length = absolute(second.Ax - second.Bx);

		// Calculate the upmost and downmost point on the coordinate system to calculate the 
		// length of the combined lines
		double minX = first.Ax;
		if (first.Bx < minX) {
			minX = first.Bx;
		}
		if (second.Ax < minX) {
			minX = second.Ax;
		}
		if (second.Bx < minX) {
			minX = second.Bx;
		}

		double maxX = first.Ax;
		if (first.Bx > maxX) {
			maxX = first.Bx;
		}
		if (second.Ax > maxX) {
			maxX = second.Ax;
		}
		if (second.Bx > maxX) {
			maxX = second.Bx;
		}

		// Calculate the length of the combined lines
		double combined = absolute(maxX - minX);

		// Calculate the length of the mutual part
		mutual = (first.length + second.length) - combined;
	}
	// Else, they do not lie on any line, parallel to any of the two axes
	
	// Return the result calculated, or the original -1 if not.
	return mutual;
}

int main() {
	line one = { 1, 5, 1, 2 };
	line two = { 1, 4, 1, -1 };

	std::cout << mutualPart(one, two) << std::endl;
		
	return 0;
}