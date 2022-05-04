#ifndef COWCULATION_H
#define COWCULATION_H

#include <string>

using namespace std;

class Cowculation
{
private:
	int num1;
	int num2;
	int result;

public:
	Cowculation();
	Cowculation(string, string, string);
	void add();
	void shiftRight();
	void shiftLeft();
	bool getResult();
	int translateCowToNum(string);
};

#endif // !COWCULATION_H