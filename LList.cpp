#include "LList.h"
#include <iostream>
#include <iomanip>
#include <string>

LList::LList() : firstNode(NULL){

}

LList::~LList() {

}

void LList::push(float entry) {
	if (sum + entry == INFINITY) {
			multiplier++;
			sum = 0;
	}
	else {
		sum += entry;
	}
	Node * newNode = new Node(entry); // new Node entry
	if (!empty()) {
		Node * tempptr = firstNode;
		while (tempptr->next_ != NULL) {
			tempptr = tempptr->next_;
		}
		tempptr->next_ = newNode;
		count++;

		max = (max > entry) ? max : entry;
		min = (min < entry) ? min : entry;
	}
	else {
		firstNode = newNode;
		count++;
		max = firstNode->entry_;
		min = firstNode->entry_;
	}
}

bool LList::empty() {
	return firstNode == NULL;
}

void LList::print(std::string day){
	if (multiplier > 0) {
		std::cout << endl << "<" << std::setfill('-') << std::setw(30)
			<< "DAILY SUMMARY" << std::setfill('-') << std::setw(30) << ">"
			<< std::endl;
		std::cout << "Your max for " << day << " was: " << max << endl
			<< "Your min " << day << " was: " << min << endl
			<< "You took a total of " << count << " readings on " << day << endl
			<< "The sum of all blood sugar reading's for " << day << " was " << FLT_MAX << " X " << multiplier 
			<< " + " << sum << endl;
		std::cout << "<" << std::setfill('-') << std::setw(60)
			<< ">" << std::endl;
	}
	else {
		std::cout << endl << "<" << std::setfill('-') << std::setw(30)
			<< "DAILY SUMMARY" << std::setfill('-') << std::setw(30) << ">"
			<< std::endl;
		std::cout << "Your max for " << day << " was: " << max << endl
			<< "Your min " << day << " was: " << min << endl
			<< "You took a total of " << count << " readings on " << day << endl
			<< "The sum of all blood sugar reading's for " << day << " was " << sum << endl;
		std::cout << "<" << std::setfill('-') << std::setw(60)
			<< ">" << std::endl;
	}
}

float LList::getMax()
{
	return max;
}

float LList::getMin()
{
	return min;
}

int LList::getCount()
{
	return count;
}

int LList::getMultiplier() {
	return multiplier;
}

float LList::getSum() {
	return sum;
}