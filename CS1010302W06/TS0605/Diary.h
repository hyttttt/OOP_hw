#ifndef DIARY_H
#define DIARY_H
#include <string>
#include <vector>

using namespace std;

class Diary {
public:
	vector<string> log;
	int currentRecordIndex;
	static vector<string> dayRecord;

	static void NewDay(string day);
	void updateDate();
};

#endif // !DIARY_H