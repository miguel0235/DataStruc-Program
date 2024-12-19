#include "stomach.h"

void stomach::eat(string name)
{

	if (name == "seed")
	{
		int size = 1;
		Q.push_front("seed", size);
		totalFood += 1;
		cout << "adding seed " << endl;
	}

	if (name == "leaf")
	{
		Q.push_front(name, 2);
		totalFood += 2;
		cout << "adding leaf " << endl;
	}

	if (name == "grass")
	{
		Q.push_front(name, 5);
		totalFood += 5;
		cout << "adding grass " << endl;
	}
}

void stomach::display()
{
	Q.display();
}

bool stomach::vomit()
{

	Q.pop_front();

	return true;
	
}

bool stomach::excrete()
{

	Q.pop_back();
	return true;
}

bool stomach::clear()
{
	return true;
}

void stomach::status()
{

}