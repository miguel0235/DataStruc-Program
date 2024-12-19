#include "Tokenizer.h"

void Tokenizer::setString(const string &str)
{
	this->str = str;
	ss.str(str);
	
	
}

bool Tokenizer::readWord(string& data)
{
	try {
		ss >> data;
		return true;
	}catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
}

bool Tokenizer::readInteger(int& data)
{
	try {
		ss >> data;
		return true;
	}catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
}

bool Tokenizer::readDouble(int& data)
{
	try {
		ss >> data;
		return true;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
}

void Tokenizer::rewind(const string &str)
{
	ss.str();
}

void Tokenizer::clear()
{
	ss.clear();
}