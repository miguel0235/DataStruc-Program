

#include <string>
#include <sstream>
#include <iostream>

#include "Tokenizer.h"

using std::stringstream;
using namespace std;

int main()
{
	Tokenizer tkn;

	int test = 0;
	int val;
	string data;
	tkn.setString("what is 2 + 4");

	while (test <= 8)
	{
		if (tkn.readWord(data))
		{
			cout << "This is a String" << data << endl;

		}
		else
		{

		}

		if (tkn.readInteger(val))
		{
			cout << "This is a integer" << val << endl;
		}
		else
		{

		}

		if (tkn.readDouble(val))
		{
			cout << "This is a double " << val << endl;
		}
		else
		{

		}

		test++;
	}
	
}

