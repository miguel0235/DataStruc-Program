#pragma once
class StackNode
{
public:
	int data;
	StackNode* next;

	StackNode() : data(0), next(nullptr) {}
	StackNode(int data) : data(data), next(nullptr) {}
	StackNode(int data, StackNode* next) : data(data), next(next) {}
};

