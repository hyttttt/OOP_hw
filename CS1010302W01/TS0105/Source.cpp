//Name: ½²´ð¼ü
//Date: Feb 17, 2022
//Last update: Feb 17, 2022
//Problem statement: This C++ calculates the volume of a sphere according to the given radius.

#include <iostream>
#include <cmath>
#include <iomanip>

void main() {
	double radius;
	double volume;
	const double PI = 3.14159265358979323846;

	while (std::cin >> radius) {
		volume = 4.0 / 3.0 * std::pow(radius, 3.0) * PI;
		std::cout << std::fixed << std::setprecision(6) << volume << std::endl;
	}
}