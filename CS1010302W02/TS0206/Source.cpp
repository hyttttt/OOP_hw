//Name: ½²´ð¼ü
//Date: Mar 1, 2022
//Last update: Mar 1, 2022
//Problem statement: This C++ program calculate tax according to the income

#include <iostream>
#include <iomanip>

int main() {
	double income;
	double tax;

	while (std::cin >> income) {
		if (income < 750.0)
			tax = 0.01 * income;
		
		else if (income >= 750.0 && income < 2250.0) 
			tax = 7.5 + 0.02 * (income - 750.0);
		
		else if (income >= 2250.0 && income < 3750.0)
			tax = 37.5 + 0.03 * (income - 2250.0);

		else if (income >= 3750.0 && income < 5250.0)
			tax = 82.5 + 0.04 * (income - 3750.0);

		else if (income >= 5250.0 && income < 7000.0)
			tax = 142.5 + 0.05 * (income - 5250.0);

		else if (income >= 7000.0)
			tax = 230.0 + 0.06 * (income - 7000.0);

		std::cout << std::fixed << std::setprecision(2) << tax << std::endl;
	}
}