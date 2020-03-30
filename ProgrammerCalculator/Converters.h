#include <iostream>
#include <string>

using namespace std;

class Converter
{
public:
	string ConvertFromBinaryToOctal(string binaryToConvert);
	string ConvertFromBinaryToDecimal(string binaryToConvert);
	string ConvertFromBinaryToHexademical(string binaryToConvert);

	string ConvertFromOctalToBinary(string octalToConvert);
	string ConvertFromOctalToDecimal(string octalToConvert);
	string ConvertFromOctalToHexademical(string octalToConvert);

	string ConvertFromDecimalToBinary(string decimalToConvert);
	string ConvertFromDecimalToOctal(string decimalToConvert);
	string ConvertFromDecimalToHexadecimal(string decimalToConvert);

	string ConvertFromHexadecimalToBinary(string hexadecimalToConvert);
	string ConvertFromHexadecimalToOctal(string hexadecimalToConvert);
	string ConvertFromHexadecimalToDecimal(string hexadecimalToConvert);
};

#pragma region Binary converters
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
#pragma endregion

#pragma region Octal converters
string Converter::ConvertFromOctalToBinary(string octalToConvert)
{
	string binaryNumber;

	int octal = stoi(octalToConvert);

	int decimalNum = 0, binaryNum = 0, count = 0;

	//First we convert octal number into decimal number
	while (octal != 0) 
	{
		decimalNum += (octal % 10) * pow(8, count);
		++count;
		octal /= 10;
	}

	count = 1;

	//Second we convert decimal number from the first step into binary number
	while (decimalNum != 0) 
	{
		binaryNum += (decimalNum % 2) * count;
		decimalNum /= 2;
		count *= 10;
	}

	binaryNumber = to_string(binaryNum);

	return binaryNumber;
}

string Converter::ConvertFromOctalToDecimal(string octalToConvert)
{
	string decimalNumber;

	int octal = stoi(octalToConvert);

	int decimalNum = 0, count = 0;

	while (octal != 0) 
	{
		decimalNum += (octal % 10) * pow(8, count);
		++count;
		octal /= 10;
	}

	decimalNumber = to_string(decimalNum);

	return decimalNumber;
}

string Converter::ConvertFromOctalToHexademical(string octalToConvert)
{
	string hexademicalNumber;

	string binary;

	//First convert octal to binary
	binary = ConvertFromOctalToBinary(octalToConvert);

	//Second convert binary to hexademical
	hexademicalNumber = ConvertFromBinaryToHexademical(binary);

	return hexademicalNumber;
}
#pragma endregion

#pragma region Decimal converters
string Converter::ConvertFromDecimalToBinary(string decimalToConvert)
{
	string binary;

	int decimalNumber = stoi(decimalToConvert);

	for (int i = 0; decimalNumber > 0; i++)
	{
		binary = binary + to_string(decimalNumber % 2);
		decimalNumber = decimalNumber / 2;
	}

	reverse(binary.begin(), binary.end());

	return binary;
}

string Converter::ConvertFromDecimalToOctal(string decimalToConvert)
{
	string octal;

	int decimalNumber = stoi(decimalToConvert);

	for (int i = 0; decimalNumber > 0; i++)
	{
		octal = octal + to_string(decimalNumber % 8);
		decimalNumber = decimalNumber / 8;
	}

	//Since for construction fills octal number in reverse way. We must to reserve octal number 
	reverse(octal.begin(), octal.end());

	return octal;
}

string Converter::ConvertFromDecimalToHexadecimal(string decimalToConvert)
{
	string hexadecimal;

	int decimalNumber = stoi(decimalToConvert);
	int remainder=0;

	for (int i = 0; decimalNumber > 0; i++)
	{
		remainder = decimalNumber % 16;
		decimalNumber = decimalNumber / 16;

		if (remainder > 9)
		{
			char letterToAdd = remainder + 55;
			hexadecimal = hexadecimal + letterToAdd;
		}
		else
			hexadecimal = hexadecimal + to_string(remainder);
	}

	reverse(hexadecimal.begin(), hexadecimal.end());

	return hexadecimal;
}
#pragma endregion

#pragma region Hexadecimal converters
string Converter::ConvertFromHexadecimalToDecimal(string hexadecimalToConvert)
{
	string decimal;
	int decimalNumber = 0;

	//reverse in order to start take numbers from the end
	reverse(hexadecimalToConvert.begin(), hexadecimalToConvert.end());

	for (int i = 0; i < hexadecimalToConvert.length(); i++)
	{
		int symbol = hexadecimalToConvert[i];
		int temp = 0;

		//bigger or equal to 65 since letters that can be in hexadecimal is A,B,C,D,E and F which in integer represents from 65 to 71
		if (symbol >= 65)
			temp = symbol - 55;
		else
			temp = stoi(hexadecimalToConvert.substr(i, 1));

		decimalNumber += temp * pow(16, i);
	}

	decimal = to_string(decimalNumber);

	return decimal;
}

string Converter::ConvertFromHexadecimalToBinary(string hexadecimalToConvert)
{
	string binary;

	//First we convert hexadecimal to decimal
	string decimal = ConvertFromHexadecimalToDecimal(hexadecimalToConvert);

	//Second we convert decimal from the first step to binary
	binary = ConvertFromDecimalToBinary(decimal);

	return binary;
}

string Converter::ConvertFromHexadecimalToOctal(string hexadecimalToConvert)
{
	string octal;

	//First convert from hexadecimal to decimal
	string decimal = ConvertFromHexadecimalToDecimal(hexadecimalToConvert);

	//Second convert from decimal to binary 
	string binary = ConvertFromDecimalToBinary(decimal);

	//Third convert from binary to octal
	octal = ConvertFromBinaryToOctal(binary);

	return octal;
}
#pragma endregion
