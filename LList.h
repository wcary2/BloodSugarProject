#include <iostream>
#include "Node.h"

#ifndef _LLIST_H_
#define _LLIST_H_

class LList {
	Node * firstNode;
	float max = 0;
	float min = 0;
	int count = 0;
	int multiplier = 0;
	float sum = 0;
public:
	LList();
	~LList();
	void push(float entry);
	bool empty();
	void print(std::string day);
	float getMax();
	float getMin();
	int getCount();
	int getMultiplier();
	float getSum();

};

#endif