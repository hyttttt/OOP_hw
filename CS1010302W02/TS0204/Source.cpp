//Name: ½²´ð¼ü
//Date: Mar 1, 2022
//Last update: Mar 1, 2022
//Problem statement: This C++ program prints out the information of enployees with standard format

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main() {
	unsigned int num;

	while (std::cin >> num) {
		int maxName = 0, maxSalary = 0, maxBonus = 0;
		std::vector<std::string> list;

		//read each set of data
		for (int i = 0; i < num; i++) {
			std::string name, salary, bonus;
			int nameLen, salaryLen, bonusLen;

			std::cin >> name >> salary >> bonus;

			list.push_back(name);
			list.push_back(salary);
			list.push_back(bonus);

			nameLen = name.size();
			salaryLen = salary.size();
			bonusLen = bonus.size();

			//find max length of name, salary, and bonus
			if (nameLen > maxName)
				maxName = nameLen;

			if (salaryLen > maxSalary)
				maxSalary = salaryLen;

			if (bonusLen > maxBonus)
				maxBonus = bonusLen;
		}

		//print out the list
		for (int i = 0; i < list.size() - 2; i = i + 3) {
			std::cout << std::setw(maxName) << list[i] << "|  "
				<< std::setw(maxSalary) << list[i + 1] << "|  "
				<< std::setw(maxBonus) << list[i + 2] << std::endl;
		}

		//clear vector
		list.clear();
	}
}