//Name: ½²´ð¼ü
//Date: Feb 17, 2022
//Last update: Feb 17, 2022
//Problem statement: This C++ sets the width of the input number to meet at least 10 digits.

#include <iostream>
#include <iomanip>
#include <string>

void main() {
	std::string num;

	while (std::cin >> num) {
		std::cout << std::setw(10) << num << std::endl;
	}
}