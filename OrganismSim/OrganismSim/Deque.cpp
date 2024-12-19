#include "Deque.h"

Deque::~Deque()
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;

		tmp = head;
	}

	tail = nullptr;
}

void Deque::push_front(string food, int size)
{
	Node* tmp = new Node(food, size);
	
	tmp->next = head;

	if (head == nullptr)
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}

	head = tmp;
}

void Deque::push_back(string food, int size)
{
	Node* tmp = new Node(food, size);

	tmp->prev = tail;

	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}

	tail = tmp;
}

bool Deque::pop_front()
{
	Node* tmp = head; 

	if (head == nullptr) return false;

	head = head->next;

	if (head == nullptr) tail = nullptr;

	delete tmp;
	
	return true;
}

/// <summary>
///                                               crash
/// </summary>
/// <returns></returns>
bool Deque::pop_back() 
{
	Node* tmp = tail;

	if (tail->prev == nullptr) return false;

	tail = tmp->prev;

	tail->next = nullptr;

	delete tmp;
	return true;

}

bool Deque::peek_front(string& food, int& size)
{
	if (head == nullptr) return false;

	food = head->foodName;
	size = head->foodSize;

	return true;
}

bool Deque::peek_back(string& food, int& size)
{
	Node* tmp = tail;
	if (head == nullptr) return false;

	food = tmp->foodName;
	size = tmp->foodSize;

	return true;
}


void Deque::display()
{
	Node* tmp = head;

	if (tmp == nullptr)
	{
		
	}
	else
	{
		while (tmp != nullptr)
		{
			cout << tmp->foodName << " " << foodSize << endl;

			tmp = tmp->next;
		} 
	}
}




