#include "Stack.h"

void Stack::push(double data)
{
	top = new StackNode(data, top);
}

bool Stack::pop()
{
	if (top == nullptr) return false;
	StackNode* tmp = top;
	top = top->next;
	delete tmp;
	return true;
}
bool Stack::peek(double& data)
{
	if (top == nullptr) return false;
	data = top->data;
	return true;
}

void Stack::display(ostream& os)
{
	StackNode* tmp = top;
	while (tmp != nullptr)
	{
		os << tmp->data << endl;
		tmp = tmp->next;
	}
}

bool Stack::isEmpty()
{
	try
	{
		ss.peek();
		return false;
	}
	catch (...)
	{
		return true;
	}

}