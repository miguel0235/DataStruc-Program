#pragma once

#include <string>
#include <sstream>
#include <iostream>

using std::stringstream;
using namespace std;

class Tokenizer
{
	private:

		stringstream ss;
		string str;

	public:
		Tokenizer() { ss.exceptions(std::ios::failbit);}
		void setString(const string &str);
		bool readWord(string &data);
		bool readInteger(int &data);
		bool readDouble(int& data);
		void rewind(const string &str);
		void clear();




};

