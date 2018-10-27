#pragma once
#include "Node.h"
#include "LList.h"
#include <string>

class Week {
	LList week[7];
	float max = -1;
	float min;
	float sum = 0;
	int count = 0;
	int pos = 0;
	int maxMultiplier = 0;
	int sumMultiplier = 0;

	int changeCountMin, changeCountMax = 0;

	

	std::string dayOfWeekMin = "Sunday";
	std::string dayOfWeekMax = "Sunday";
	std::string changeDayMin = "Sunday";
	std::string changeDayMax = "Sunday";

public:
	bool nextDay();
	void nextEntry(float entry);
	void print();
	void sumFunction();
	void printDay();
	float getMax();
	float getMin();
	int getCount();
	std::string getDay();

};