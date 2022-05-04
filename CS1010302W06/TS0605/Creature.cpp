#include "Creature.h"
#include <iostream>

//Intent: Constructor of the Creature with its name
//Pre: Input a string that is its name
//Post: Create a Creature and write down the log
Creature::Creature(string name) {
	this->name = name;
	this->cDiary.log.push_back(name + "'s log:\n");
	this->cDiary.currentRecordIndex = Diary::dayRecord.size() - 1;
	this->cDiary.log.push_back("Day " + Diary::dayRecord[this->cDiary.currentRecordIndex] + "\n");
}

//Intent: Copy Constructor of Creature
//Pre: Input a Creature
//Post: Copy the part of another Creature and create one
Creature::Creature(string name, Creature c) {
	this->name = name;
	for (const auto& s : c.status) {
		this->status[s.first] = s.second;
	}
	this->cDiary.log.push_back(name + "'s log:\n");
	this->cDiary.currentRecordIndex = Diary::dayRecord.size() - 1;
	this->cDiary.log.push_back("Day " + Diary::dayRecord[this->cDiary.currentRecordIndex] + "\n");
}

//Intent: Overload [] to get the number of the Creature's part
//Pre: Input the part name
//Post: Return the Creature
Creature& Creature::operator[](string part) {
	this->searchPart = part;

	this->cDiary.updateDate();

	//find part
	map<string, int>::iterator iter = this->status.find(part);
	if (iter == this->status.end())
		this->status[part] = 0;

	return *this;
}

//Intent: Overload = to assign new number of the Creature's part
//Pre: Input the new number of the part
//Post: Update the number of the Creature's part
Creature& Creature::operator=(int num) {
	int oldNum = this->status[this->searchPart];
	int newNum = num;

	if (newNum != oldNum) {
		this->updateLog(oldNum, newNum);
		this->status[this->searchPart] = num;
	}

	//erase empty part
	if (this->status[this->searchPart] == 0) {
		this->status.erase(this->searchPart);
	}

	return *this;
}

//Intent: Overload += to incraese the number of the Creature's part
//Pre: Input the increment
//Post: Update the number of the Creature's part
Creature& Creature::operator+=(int num) {
	int oldNum = this->status[this->searchPart];
	int newNum = num;

	if (newNum != 0) {
		this->updateLog(oldNum, oldNum + newNum);
		this->status[this->searchPart] += num;
	}

	return *this;
}

//Intent: Overload -= to decrease the number of the Creature's part
//Pre: Input the decrement
//Post: Update the number of the Creature's part
Creature& Creature::operator-=(int num) {
	int oldNum = this->status[this->searchPart];
	int newNum = num;

	if (newNum != 0) {
		this->updateLog(oldNum, oldNum - newNum);
		this->status[this->searchPart] -= num;
	}

	//erase empty part
	if (this->status[this->searchPart] == 0) {
		this->status.erase(this->searchPart);
	}

	return *this;
}

//Intent: Print the current parts and their number of the Creature
//Pre: Status can be empty
//Post: Print out the current status
void Creature::PrintStatus() {
	cout << this->name << "'s status:\n";
	for (const auto& s : this->status) {
		cout << s.first << " * " << s.second << endl;
	}
	cout << endl;
}

//Intent: Print the current log of the Creature
//Pre: Log can be empty
//Post: Print out the current log
void Creature::PrintLog() {
	this->cDiary.updateDate();

	for (int i = 0; i < this->cDiary.log.size(); i++) {
		cout << this->cDiary.log[i];
	}
	cout << endl;
}

//Intent: Update the information when Creature's part changes
//Pre: Input the original number and new number
//Post: New information is on the log
void Creature::updateLog(int oldNum, int newNum) {
	string update = this->name + "'s " + this->searchPart;
	if (oldNum == 0) {
		update += " appeared (";
	}
	else if (oldNum < newNum) {
		update += " increased (";
	}
	else if (oldNum > newNum) {
		update += " decreased (";
	}

	update += to_string(oldNum) + " -> " + to_string(newNum) + ").\n";
	this->cDiary.log.push_back(update);
}