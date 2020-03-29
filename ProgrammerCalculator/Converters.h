#include <iostream>
#include <string>

using namespace std;

class Converter
{
public:
	string ConvertFromBinaryToOctal(string binaryToConvert);
	string ConvertFromBinaryToDecimal(string binaryToConvert);
	string ConvertFromBinaryToHexademical(string binaryToConvert);

	string ConvertFromOctalToBinary(string binaryToConvert);
	string ConvertFromOctalToDecimal(string binaryToConvert);
	string ConvertFromOctalToHexademical(string binaryToConvert);
};

string Converter::ConvertFromBinaryToOctal(string binaryToConvert)
{
	int binary = stoi(binaryToConvert);

	string octalNumber;

	//We starting break our binary number by 3 bits 
	//from the end.
	while (binary != 0)
	{
		int triad = binary % 1000;//last three bits from the end of the triad
		int result = 0;

		for (int i = 0; i < 3; i++)
		{
			int remainder = 0;
			remainder = triad % 10;
			result = result + remainder * pow(2, i);
			triad = triad / 10;
		}

		binary = binary / 1000;

		octalNumber = octalNumber + to_string(result);
	}

	reverse(octalNumber.begin(), octalNumber.end());

	return octalNumber;
}

string Converter::ConvertFromBinaryToDecimal(string binaryToConvert)
{
	int binary = stoi(binaryToConvert);
	int result = 0;
	int base = 1;
	while (binary) 
	{
		int lastDigit = binary % 10;
		binary = binary / 10;
		result += lastDigit * base;
		base = base * 2;
	}

	string decimalNumber = to_string(result);

	return decimalNumber;
}

string Converter::ConvertFromBinaryToHexademical(string binaryToConvert) 
{
	string hexademicalNumber;

	int binary = stoi(binaryToConvert);

	//We starting break our binary number by 4 bits 
	//from the end.
	while (binary != 0)
	{
		int tetrad = binary % 10000;//last four bits from the end of the triad
		int result = 0;

		for (int i = 0; i < 4; i++)
		{
			int remainder = 0;
			remainder = tetrad % 10;
			result = result + remainder * pow(2, i);
			tetrad = tetrad / 10;
		}

		if (result > 9)
		{
			char letterToAdd = result + 55;
			hexademicalNumber = hexademicalNumber + letterToAdd;
		}
		else
			hexademicalNumber = hexademicalNumber + to_string(result);

		binary = binary / 10000;
	}

	reverse(hexademicalNumber.begin(), hexademicalNumber.end());

	return hexademicalNumber;
}
