//Name: ½²´ğ¼ü
//Date: Mar 1, 2022
//Last update: Mar 1, 2022
//Problem statement: This C++ program adds two large numbers

#include <iostream>
#include <algorithm>

struct BigInt {
	std::string num = "";
	int length = 0;
};

BigInt addBigInt(const BigInt& lhs, const BigInt& rhs) {
	std::string numA, numB;

	//make sure numA is always the bigger one
	if (lhs.length >= rhs.length) {
		numA = lhs.num;
		numB = rhs.num;
	}
	else {
		numA = rhs.num;
		numB = lhs.num;
	}

	//reverse numA and numB
	std::reverse(numA.begin(), numA.end());
	std::reverse(numB.begin(), numB.end());

	int carry = 0;
	std::string strSum = "";

	//add until numB (smaller one) is done
	for (int i = 0; i < numB.size(); i++) {
		int intSum = (numA[i] - '0') + (numB[i] - '0') + carry;
		carry = intSum / 10;
		strSum += (char)((intSum %= 10) + '0');
	}

	//add the rest of numA (bigger one)
	for (int i = numB.size(); i < numA.size(); i++) {
		int intSum = (numA[i] - '0') + carry;
		carry = intSum / 10;
		strSum += (char)((intSum %= 10) + '0');
	}

	//add the remained carry
	if(carry)
		strSum += ((char)(carry)+'0');

	//reverse the sum
	std::reverse(strSum.begin(), strSum.end());

	BigInt result;
	result.num = strSum;
	result.length = strSum.size();

	return result;
}

bool isNum(std::string num) {
	for (int i = 0; i < num.size(); i++) {
		if (!isdigit(num[i]))
			return false;
	}

	return true;
}

int main(){
	int times;
	std::cin >> times;

	for (int i = 0; i < times; i++) {
		std::string num1, num2;
		std::cin >> num1 >> num2;
		
		if (isNum(num1) && isNum(num2)) {
			BigInt big1, big2;
			big1.num = num1;
			big1.length = num1.size();
			big2.num = num2;
			big2.length = num2.size();

			std::cout << addBigInt(big1, big2).num << std::endl;
		}
		else {
			std::cout << "Not a valid number, please try again.\n";
		}
	}
}