#include <iostream>
#include <string>

using namespace std;

class Validator // validator for numbers
{ 
private:
	string symbolsForBinary{ "01" };
	string symbolsForHex{ "0123456789ABCDEF" };
	string symbolsForDec{ "0123456789" };
	string symbolsForOctal{ "01234567" };

public:
	bool IsCorrectBinary(string stringForCheck) 
	{
		for (int i = 0; i < stringForCheck.length(); ++i) 
		{
			int dismatch = 0; // number of times when symbols didn't match

			for (int k = 0; k < symbolsForBinary.length(); ++k) 
			{
				if (stringForCheck[i] == symbolsForBinary[k])
					break; // if the symbols match, go to the next symbol in number
				else
				{
					dismatch++;

					if (dismatch == 2) // if the symbol in a number didn't match with all symbols in binary, then return false
					{
						cout << "There is invalid symbol found: " << stringForCheck[i] << endl;
						return false;
					}
				}
			}
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