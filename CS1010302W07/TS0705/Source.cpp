//Name: ½²´ð¼ü
//Date: Apr 5, 2022
//Last update: Apr 5, 2022
//Problem statement: Do calculation with a quarternary system called "Cowculation"

#include <iostream>
#include "Cowculation.h"

int main() {
	int tableNum;
	while (cin >> tableNum) {
		cout << "COWCULATIONS OUTPUT\n";

		//read each table
		for (int i = 0; i < tableNum; i++) {
			string num1, num2, result;
			char op[3];
			cin >> num1 >> num2 >> op[0] >> op[1] >> op[2] >> result;

			Cowculation cow(num1, num2, result);

			//operation
			for (int j = 0; j < 3; j++) {
				if (op[j] == 'A')
					cow.add();

				else if (op[j] == 'R')
					cow.shiftRight();

				else if (op[j] == 'L')
					cow.shiftLeft();
			}

			//comparison
			if (cow.getResult())
				cout << "YES\n";
			else
				cout << "NO\n";
		}

		cout << "END OF OUTPUT";
	}

	return 0;
}