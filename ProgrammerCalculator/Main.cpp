#include <iostream>
#include <string>
#include "Converters.h"
#include "Validators.h"

using namespace std;

void ShowMenu() 
{
	cout << endl << endl;

	cout << "Please, enter command symbol:" << endl << endl;

	cout << "1. Convert from decimal to binary" << endl;
	cout << "2. Convert from decimal to octal" << endl;
	cout << "3. Convert from decimal to hexadecimal" << endl << endl;
	cout << "4. Convert from binary to decimal" << endl;
	cout << "5. Convert from binary to octal" << endl;
	cout << "6. Convert from binary to hexadecimal" << endl << endl;
	cout << "7. Convert from octal to binary" << endl;
	cout << "8. Convert from octal to decimal" << endl;
	cout << "9. Convert from octal to hexadecimal" << endl << endl;
	cout << "0. Convert from hexadecimal to binary" << endl;
	cout << "a. Convert from hexadecimal to decimal" << endl;
	cout << "b. Convert from hexadecimal to octal" << endl << endl;
	cout << "x. Exit the program" << endl;

}

void CheckForDec(string &str) 
{
	Validator check;
	do 
	{
		cout << "Enter the decimal number: ";
		cin >> str;
	} while (!check.IsCorrectDec(str));
}

void CheckForBinary(string& str) 
{
	Validator check;
	do 
	{
		cout << "Enter the binary number: ";
		cin >> str;
	} while (!check.IsCorrectBinary(str));
}

void CheckForOctal(string& str) 
{
	Validator check;
	do 
	{
		cout << "Enter the octal number: ";
		cin >> str;
	} while (!check.IsCorrectOctal(str));
}

void CheckForHex(string& str)
{
	Validator check;
	do 
	{ 
		cout << "Enter the hexadecimal number: ";
		cin >> str;
		for (auto& c : str) c = toupper(c);
	} while (!check.IsCorrectHex(str));
}

void RunProgram()
{
	char selection = ' ';
	string number;
	Converter convert;

	do
	{
		ShowMenu();
		cin >> selection;

	if (selection == '1') 
	{
		string binary;
		CheckForDec(number);
		cout << "Converting process..." << endl;
		binary = convert.ConvertFromDecimalToBinary(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The binary representation is " << binary << endl;
	}
	else if (selection == '2') 
	{
		string octal;
		CheckForDec(number);
		cout << "Converting process..." << endl;
		octal = convert.ConvertFromDecimalToOctal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The octal representation is " << octal << endl;
	}
	else if (selection == '3') 
	{
		string hex;
		CheckForDec(number);
		cout << "Converting process..." << endl;
		hex = convert.ConvertFromDecimalToHexadecimal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The hexadecimal representation is " << hex << endl;
	}
	else if (selection == '4') 
	{
		string dec;
		CheckForBinary(number);
		cout << "Converting process..." << endl;
		dec = convert.ConvertFromBinaryToDecimal(number);
		cout << "Converting process has finished" << endl;
		cout << "The decimal representation is " << dec << endl;
	}
	else if (selection == '5')
	{
		string octal;
		CheckForBinary(number);
		cout << "Converting process..." << endl;
		octal = convert.ConvertFromBinaryToOctal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The octal representation is " << octal << endl;
	}
	else if (selection == '6') 
	{
		string hex;
		CheckForBinary(number);
		cout << "Converting process..." << endl;
		hex = convert.ConvertFromBinaryToHexadecimal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The hexadecimal representation is " << hex << 	endl;
	}
	else if (selection == '7')
	{
		string binary;
		CheckForOctal(number);
		cout << "Converting process..." << endl;
		binary = convert.ConvertFromOctalToBinary(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The binary representation is " << binary << endl;
	}
	else if (selection == '8')
	{
		string decimal;
		CheckForOctal(number);
		cout << "Converting process..." << endl;
		decimal = convert.ConvertFromOctalToDecimal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The decimal representation is " << decimal << endl;
	}
	else if (selection == '9')
	{
		string hex;
		CheckForOctal(number);
		cout << "Converting process..." << endl;
		hex = convert.ConvertFromOctalToHexadecimal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The hexadecimal representation is " << hex << endl;
	}
	else if (selection == '0')
	{
		string binary;
		CheckForHex(number);
		cout << "Converting process..." << endl;
		binary = convert.ConvertFromHexadecimalToBinary(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The binary representation is " << binary << endl;
	}
	else if (selection == 'a' || selection == 'A') 
	{
		string decimal;
		CheckForHex(number);
		cout << "Converting process..." << endl;
		decimal = convert.ConvertFromHexadecimalToDecimal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The decimal representation is " << decimal << endl;
	}
	else if (selection == 'b' || selection == 'C') 
	{
		string octal;
		CheckForHex(number);
		cout << "Converting process..." << endl;
		octal = convert.ConvertFromHexadecimalToOctal(number);
		cout << "Converting process has finished" << endl << endl;
		cout << "The octal representation is " << octal << endl;
	}
	else if (selection == 'x' || selection == 'X')
		cout << "Good Luck" << endl;
	else
		cout << "Invalid command, please try again" << endl;

	} while (selection != 'x' && selection != 'X');
}

int main()
{
	cout << "Welcome to our programming calculator.\nYou can see the options above and their corresponding symbols.";
	cout << "There are commands to select and for your convenience you can type uppercase or lowercase" << endl;

	RunProgram();

	system("pause");

	return 0;
}