//Name: ½²´ð¼ü
//Date: Mar 15, 2022
//Last update: Mar 15, 2022
//Problem statement: This C++ program generate the greatest common divisor of two positive integers

#include <iostream>

int makeGCD(int numA, int numB) {
	if (numB == 0)
		return numA;
	return makeGCD(numB, numA % numB);
}

int main() {
	int numA, numB;
	while (std::cin >> numA >> numB) {
		std::cout << makeGCD(numA, numB) << std::endl;
	}
}