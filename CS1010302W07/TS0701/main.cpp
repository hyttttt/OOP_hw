//FormWord-inputmain1.cpp
//Name: ½²´ð¼ü
//Date: Apr 5, 2022
//Last update: Apr 5, 2022
//Problem statement: This C++ program simulates a word game.

#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("words.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers
	return 0;
}