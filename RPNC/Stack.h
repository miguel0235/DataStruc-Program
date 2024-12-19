#pragma once
#include "StackNode.h"
#include <iostream>

using std::ostream;
using std::endl;

class Stack
{
private:
	StackNode* top;

public:
	Stack() : top(nullptr) {}

	void push(double data);
	bool pop();
	bool peek(double& data);
	void display(ostream& os);
	bool isEmpty();

};

