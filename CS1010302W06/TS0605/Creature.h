#ifndef CREATURE_H
#define CREATURE_H
#include "Diary.h"
#include <map>

using namespace std;

class Creature {
private:
	string name;
	string searchPart;
	map<string, int> status;
	Diary cDiary;

public:
	Creature(string name);
	Creature(string name, Creature c);
	Creature& operator[](string part);
	Creature& operator=(int num);
	Creature& operator+=(int num);
	Creature& operator-=(int num);
	void PrintStatus();
	void PrintLog();
	void updateLog(int oldNum, int newNum);
};

#endif // !CREATURE_H