//Name: ½²´ð¼ü
//Date: Mar 9, 2022
//Last update: Mar 9, 2022
//Problem statement: This C++ program calculate the CPU bits growth

#include <iostream>
#include <math.h>

int main() {
	int year;
	while (std::cin >> year) {
		int bitPower = (year - 1900) / 10 + 2;
		long double bit = pow(2.0, bitPower);

		long double num = 0;
		int count = 0;

		/*
			max = (2^bit - 1)
			N! <= max
			log2(N!) <= log2(max)
			log2(1) + log2(2) + ... + log2(N) <= bit
		*/

		do {
			count++;
			num += log2(double(count));
		} while (num <= bit);

		count--;

		std::cout << count << std::endl;
	}
}