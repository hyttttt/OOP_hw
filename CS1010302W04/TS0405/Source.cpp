//Name: ½²´ð¼ü
//Date: Mar 15, 2022
//Last update: Mar 15, 2022
//Problem statement: This C++ program simulates Collatz conjecture, find the most cycle number in the range

#include <iostream>

int times = 0;

void collatzConjecture(int num) {

	if (num == 1)
		return;
	
	//even num
	if (num % 2 == 0) {
		collatzConjecture(num / 2);
		times++;
	}
	//odd num
	else {
		collatzConjecture(num * 3 + 1);
		times++;
	}
}

int main() {
	int num1, num2;
	while (std::cin >> num1 >> num2) {
		int max = 0;
		int big, small;

		//find the range
		if (num1 > num2) {
			big = num1;
			small = num2;
		}
		else {
			big = num2;
			small = num1;
		}

		for (int i = small; i <= big; i++) {
			times = 1;
			collatzConjecture(i);
			if (times > max)
				max = times;
		}

		std::cout << num1 << " " << num2 << " " << max << std::endl;
	}
}