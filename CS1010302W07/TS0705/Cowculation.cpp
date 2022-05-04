#include "Cowculation.h"
#include <math.h>
#include <iostream>

//Intent: Default constructor of Cowculation
//Pre: No input needed
//Post: Construct a Cowculation object with all member being 0
Cowculation::Cowculation() {
	this->num1 = 0;
	this->num2 = 0;
	this->result = 0;
}

//Intent: Constructor of Cowculation
//Pre: No input needed
//Post: Construct a Cowculation object with num1 and num2 being set
Cowculation::Cowculation(string num1, string num2, string result) {
	this->num1 = this->translateCowToNum(num1);
	this->num2 = this->translateCowToNum(num2);
	this->result = this->translateCowToNum(result);
}

//Intent: Translate the cow number into decimal number
//Pre: Input a string that is cow number
//Post: Return a decimal number
int Cowculation::translateCowToNum(string cow) {
	int result = 0;

	for (int i = 0; i < cow.size(); i++) {
		int num = 0;
		if (cow[i] == 'V')
			num = 0;
		else if (cow[i] == 'U')
			num = 1;
		else if (cow[i] == 'C')
			num = 2;
		else if (cow[i] == 'D')
			num = 3;

		int power = cow.size() - i - 1;
		result += int(num * pow(4.0, power));
	}
	return result;
}

//Intent: Add num1 to num2
//Pre: Num1 and num2 are set
//Post: Num2 now equals num2 plus num1
void Cowculation::add() {
	this->num2 += this->num1;
}

//Intent: Shift right operation on num2, which means divide num2 by 4
//Pre: Num2 is set
//Post: Divide num2 by 4
void Cowculation::shiftRight() {
	this->num2 /= 4;
}

//Intent: Shift left operation on num2, which means multiply num2 by 4
//Pre: Num2 is set
//Post: Multiply num2 by 4
void Cowculation::shiftLeft() {
	this->num2 *= 4;
}

//Intent: Determine whether the result is correct
//Pre: All operations are finished
//Post: Return whether the result is correct
bool Cowculation::getResult() {
	if (this->num2 == this->result)
		return true;
	else
		return false;
}