#include "Tokenizer.h"
#include "Deque.h"
#include "stomach.h"

#include <fstream>
#include <iostream>  
#include <string>
#include <iomanip>


using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


/// <summary>
///                                                Fix Display Func while in stomach
/// <returns></returns>
bool processText(istream& is, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	double darg1, darg2;
	Tokenizer tkn;

	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				// keeping in mind the note about the definition for the processText fuction
																	// the following line of code is closer to
				// status = processText(fin, b, false);
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}
		if (command == "Dequetest")
		{
			Deque Q;

			string out;
			int test;

			Q.push_back("test1", 1);
			Q.push_back("test2", 2);
			Q.push_back("test3", 3);
			Q.push_back("test4", 4);
			Q.push_back("test5", 5);
			Q.push_front("test6", 6);
			cout << "1-5 Numbers added" << endl;
			Q.display();
			cout << "*****************" << endl;
			Q.pop_back();
			Q.pop_front();


			cout << "Popped 6 and 5" << endl;
			Q.display();
			cout << "*****************" << endl;
			
			cout << "Testing peek" << endl;

			Q.peek_front(out, test);
			cout << "Front: " <<  out << " " << test << endl;
			Q.peek_back(out, test);
			cout << "Back: "  << out << " " << test << endl;

			cout << "*****************" << endl;
			Q.display();
		}
		if (command == "test")
		{
			stomach s;

			cout << "Starting ammounts " << endl;
			s.display();

			cout << "************" << endl;
			cout << "Ate seed" << endl;
			s.eat("seed");

			s.display();

			cout << "************" << endl;
			cout << "Ate leaf" << endl;

			s.display();

			cout << "************" << endl;
			cout << "Ate seed" << endl;

			s.eat("grass");

		}
	}


}

void menu();
int main()
{
	// the following line of code is normally closer to this
	// <type> inst;
	// processText(cin, inst);
	// where <type> is the type of the data structure we are working with
	processText(cin);
	return 0;

}

void menu()
{

}