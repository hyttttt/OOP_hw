#include "Diary.h"

vector<string> Diary::dayRecord;

//Intent: Add a new day in day record
//Pre: Input a new day's title 
//Post: A new day is in day record
void Diary::NewDay(string day) {
	dayRecord.push_back(day);
}

//Intent: Update the date in the log
//Pre: Day record is not empty
//Post: The missing days are updated in the log
void Diary::updateDate() {
	if (this->currentRecordIndex != dayRecord.size() - 1) {
		for (int i = this->currentRecordIndex + 1; i < dayRecord.size(); i++) {
			this->log.push_back("Day " + dayRecord[i] + "\n");
		}
	}

	this->currentRecordIndex = dayRecord.size() - 1;
}