#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Validator // validator for numbers
{
private:
	string symbolsForBinary{ "01" };
	string symbolsForHex{ "0123456789ABCDEF" };
	string symbolsForDec{ "0123456789" };
	string symbolsForOctal{ "01234567" };

	void ShowMarkedErrors(string sourceString, vector<char> wrongSymbols)
	{
		//Read this(https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c) to see how change color of text of console app
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		cout << endl << "Error input!" << endl;

		cout << "String with marked error(s):" << endl;

		for (int i = 0; i < sourceString.size();)
		{
			for (int a = 0; a < wrongSymbols.size(); a++)
				if (sourceString[i] == wrongSymbols[a])
				{
					SetConsoleTextAttribute(hConsole, 2);//Second parameter is code of color. Look code of color here http://cppqa.blogspot.com/2013/11/colour-coding-in-c-first-time-i-saw.html
					cout << sourceString[i];
					SetConsoleTextAttribute(hConsole, 7);//Second parameter is code of color. Look code of color here http://cppqa.blogspot.com/2013/11/colour-coding-in-c-first-time-i-saw.html
					i++;
				}

			cout << sourceString[i];
			i++;
		}

		cout << endl;

		cout << "Please fix error(s)." << endl;
	}

public:
	bool IsCorrectBinary(string stringForCheck)
	{
		vector<char> wrongSymbols;//Read this(https://stackoverflow.com/questions/755835/how-to-add-element-to-c-array)
		bool isCorrectBinary = true;//Flag that shows that input binary is correct or no

		for (int i = 0; i < stringForCheck.length(); ++i)
		{
			int dismatch = 0; // number of times when symbols didn't match

			for (int k = 0; k < symbolsForBinary.length(); ++k)
			{
				if (stringForCheck[i] != symbolsForBinary[k])
				{
					dismatch++;

					if (dismatch == 2) // if the symbol in a number didn't match with all symbols in binary, then return false
					{
						wrongSymbols.push_back(stringForCheck[i]);
						isCorrectBinary = false;
					}
				}
			}
		}

		if (!isCorrectBinary)
		{
			ShowMarkedErrors(stringForCheck, wrongSymbols);

			return false;
		}

		return true;
	}

	// Same algorithm used below for the rest methods with some little changes. For example, dismatch depends on the base system
	bool IsCorrectHex(string stringForCheck)
	{
		for (int i = 0; i < stringForCheck.length(); ++i)
		{
			int dismatch = 0;

			for (int k = 0; k < symbolsForHex.length(); ++k)
			{
				if (stringForCheck[i] == symbolsForHex[k])
					break;
				else
				{
					dismatch++;

					if (dismatch == 16)
					{
						cout << "There is invalid symbol found: " << stringForCheck[i] << endl;
						return false;
					}
				}
			}
		}

		return true;
	}

	bool IsCorrectDec(string stringForCheck)
	{
		for (int i = 0; i < stringForCheck.length(); ++i)
		{
			int dismatch = 0;

			for (int k = 0; k < symbolsForDec.length(); ++k)
			{
				if (stringForCheck[i] == symbolsForDec[k])
					break;
				else
				{
					dismatch++;

					if (dismatch == 10)
					{
						cout << "There is invalid symbol found: " << stringForCheck[i] << endl;
						return false;
					}
				}
			}
		}

		return true;
	}

	bool IsCorrectOctal(string stringForCheck)
	{
		for (int i = 0; i < stringForCheck.length(); ++i)
		{
			int dismatch = 0;

			for (int k = 0; k < symbolsForOctal.length(); ++k)
			{
				if (stringForCheck[i] == symbolsForOctal[k])
					break;
				else
				{
					dismatch++;

					if (dismatch == 8)
					{
						cout << "There is invalid symbol found: " << stringForCheck[i] << endl;
						return false;
					}
				}
			}
		}

		return true;
	}
};