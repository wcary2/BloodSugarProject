#include <iostream>
#include <iomanip>
#include "Week.h"

bool Week::nextDay() {
	LList tempList = week[pos];
	count += tempList.getCount();

	sumFunction();

	//checks the current day's max to test if it is greater than week max
	if (tempList.getCount() > changeCountMax) {
		changeCountMax = tempList.getCount();
		changeDayMax = getDay();
	}
	//checks the current day's min to test if it is lower than current week min
	if (tempList.getCount() < changeCountMin) {
		changeCountMin = tempList.getCount();
		changeDayMin = getDay();
	}
	//iterates through position of day
	if (pos == 0) {
		min = tempList.getMin();
		changeCountMin = tempList.getCount();
	}
	//changing max and min for week based on day results
	if (max < tempList.getMax()) {
		max = tempList.getMax();
		dayOfWeekMin = getDay();
	}
	//changes min for week based on current days min
	if (min > tempList.getMin()) {
		min = tempList.getMin();
		dayOfWeekMin = getDay();
	}
	
	//iterates through week and prints details of day at call of nextDay()
	week[pos].print(getDay());
	if(pos != 6){
		pos++;
		return false;
	}
	else {
		print();
		return true;
	}
}

std::string Week::getDay() {
	switch (pos) {
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5: 
		return "Friday";
	case 6:
		return "Saturday";
	}
}

void Week::nextEntry(float entry) {
	week[pos].push(entry);
	return;
}

void Week::print(){
	std::cout << endl << "<" << std::setfill('-') << std::setw(50)
		<< "WEEKLY SUMMARY" << std::setfill('-') << std::setw(50) << ">" << std::endl;
	std::cout << "Your highest blood sugar reading occured on " << dayOfWeekMax << " and was was: " << max << endl
		<< "Your lowest blood sugar reading occured on " << dayOfWeekMin << " and was: " << min << endl;
	if (sumMultiplier > 0) { // checks which version of sum to use print to use
		std::cout << "The sum of all blood sugar readings this week is: " << FLT_MAX
			<< " X " << sumMultiplier << " + " << sum << endl;
	}
	else {
		std::cout << "The sum of all blood sugar readings this week is: " << sum << endl;
	}
		
	std::cout << "The biggest change in count occured between " << changeDayMin << " at "
		<< changeCountMin << " and " << changeDayMax << " at " << changeCountMax 
		<< " for a total change of " << changeCountMax - changeCountMin << endl
		<< "You took a total of " << count << " readings" << endl;
	std::cout << "<" << std::setfill('-') << std::setw(100)
		<< ">" << std::endl << endl;
}

void Week::printDay()
{
	week[pos].print(getDay());
}

float Week::getMax()
{
	return max;
}

float Week::getMin()
{
	return min;
}

int Week::getCount() {
	return count;
}





void Week::sumFunction() {
	LList list = week[pos];
	int listMultiplier = list.getMultiplier();
	float listSum = list.getSum();
	if (listMultiplier > 0) {
		sumMultiplier += listMultiplier;
		if (listSum + sum == INFINITY) {
			sumMultiplier++;
			sum = 0;
		}
		else {
			sum += listSum;
		}
	}
}