

#include "Tokenizer.h"
#include "Stack.h"
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

// please note that the following function will normally
// have a function prototype more like
// bool processText(istream& is, <type> &b, bool interactive = true)
// where <type> is the type of the data structure we are working with
bool processText(istream& is, bool interactive = true)
{
	string line;
	string command;
	string arg1;
	double darg1;
	Tokenizer tkn;

	Stack S;

	//Class code 
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
		if (command == "exec")
		{

			int count = 0;


			// couldn't figure out how to fix the isempty check to keep loop going 
			// everything works if its forced to loop using count
			//Loop through all the calculations 
			while (!S.isEmpty())
			{
				//loop to get the numbers 
				while (tkn.readDouble(darg1))
				{

					S.push(darg1);
				}

				//read operation and do calculation 
				if (tkn.readWord(arg1))
				{

					double var1, var2;

					if (arg1 == "+")
					{

						S.peek(var1);
						S.pop();
						S.peek(var2);
						S.pop();

						//do calculation and push back to stack
						S.push(var1 + var2);
					}
					else if (arg1 == "-")
					{
						S.peek(var1);
						S.pop();
						S.peek(var2);
						S.pop();

						//do calculation and push back to stack
						S.push(var2 - var1);

					}
					else if (arg1 == "*")
					{
						S.peek(var1);
						S.pop();
						S.peek(var2);
						S.pop();

						//do calculation and push back to stack
						S.push(var1 * var2);
					}
					else if (arg1 == "/")
					{
						S.peek(var1);
						S.pop();
						S.peek(var2);
						S.pop();

						//do calculation and push back to stack
						S.push(var2 / var1);
					}
				}
				
			//count++;
			} 
		}
		S.display(cout);
		S.pop();
	}
}


int main()
{
// the following line of code is normally closer to this
// <type> inst;
// processText(cin, inst);
// where <type> is the type of the data structure we are working with
	processText(cin);
	return 0;
}