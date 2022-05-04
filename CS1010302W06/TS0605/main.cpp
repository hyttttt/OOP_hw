//Name: ½²´ð¼ü
//Date: Apr 5, 2022
//Last update: Apr 5, 2022
//Problem statement: This C++ program is the observation diary for some creatures

#include "Diary.h"
#include "Creature.h"

int main() {

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 26;
	unknownA.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA["wing"] -= 2;
	unknownA.PrintLog();
	unknownA.PrintStatus();

	Creature unknownC("UC", unknownB);
	Diary::NewDay("0411");
	unknownC["hand"] += 1;
	/*unknownC["hand"] = 0;
	unknownC["hand"] -= 3;
	unknownC["hand"] = 8;
	unknownC["hand"] = 20;*/
	Diary::NewDay("0523");
	unknownA.PrintLog();
	unknownB.PrintLog();
	unknownC.PrintLog();
	unknownC.PrintStatus();
}
