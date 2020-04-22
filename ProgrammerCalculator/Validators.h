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

	bool FindErrors(string stringForCheck, vector<char>& wrongSymbols,string availableSymbols)
	{
		bool isCorrectString = true;

		for (int i = 0; i < stringForCheck.length(); ++i)
		{
			for (int k = 0; k < symbolsForBinary.length(); ++k)
			{
				//Read this to see how this statement work(https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c)
				if (availableSymbols.find(stringForCheck[i]) == string::npos)//string::npos is constant with value -1. Usually uses to show that it is not any matches. Read this(https://stackoverflow.com/questions/3827926/what-does-stringnpos-mean-in-this-code)
				{
					wrongSymbols.push_back(stringForCheck[i]);
					isCorrectString = false;
				}
			}
		}

		return isCorrectString;
	}
public:
	bool IsCorrectBinary(string stringForCheck)
	{
		vector<char> wrongSymbols;//Read this(https://stackoverflow.com/questions/755835/how-to-add-element-to-c-array)
		bool isCorrectBinary = true;//Flag that shows that input binary is correct or no

		isCorrectBinary = FindErrors(stringForCheck, wrongSymbols, symbolsForBinary);

		if (!isCorrectBinary)
		{
			ShowMarkedErrors(stringForCheck, wrongSymbols);

			return false;
		}

		return true;
	}

	bool IsCorrectHex(string stringForCheck)
	{
		vector <char> wrongSymbols;
		bool isCorrectHex = true;

		isCorrectHex = FindErrors(stringForCheck, wrongSymbols, symbolsForHex);

		if (!isCorrectHex)
		{
			ShowMarkedErrors(stringForCheck, wrongSymbols);

			return false;
		}

		return true;
	}

	bool IsCorrectDec(string stringForCheck)
	{
		vector <char> wrongSymbols;
		bool isCorrectDec = true;

		isCorrectDec = FindErrors(stringForCheck, wrongSymbols, symbolsForDec);

		if (!isCorrectDec)
		{
			ShowMarkedErrors(stringForCheck, wrongSymbols);

			return false;
		}

		return true;
	}

	bool IsCorrectOctal(string stringForCheck)
	{
		vector <char> wrongSymbols;
		bool isCorrectOctal = true;

		isCorrectOctal = FindErrors(stringForCheck, wrongSymbols, symbolsForOctal);

		if (!isCorrectOctal)
		{
			ShowMarkedErrors(stringForCheck, wrongSymbols);

			return false;
		}

		return true;
	}
};