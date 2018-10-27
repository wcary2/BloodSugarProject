//Blood Sugar Project
//William Cary
//Oct 26 2018

#pragma once
#ifndef NODE_H_
#define NODE_H_
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

class Node
{
public:
	double entry_;
	Node * next_;
public:
	explicit Node(float entry);
	Node(float entry, Node * next);
	~Node();
private:
	const Node & operator=(const Node &);
};

#endif 