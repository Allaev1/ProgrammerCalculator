#include <iostream>
#include <string>
#include "Model.h"
#include "Converters.h"
#include "Validators.h"

using namespace std;

void RunProgram()
{

}

int main()
{
	RunProgram();
	Validator proto;
	string number{ "765" };

	if (proto.is_correct_octal(number))
		cout << "Correct" << endl;
	else
		cout << "Please, try again" << endl;


	system("pause");

	return 0;
}