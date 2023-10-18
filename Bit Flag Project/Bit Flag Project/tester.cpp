/*
* This is a program to test my header in making bit flags out of enums
* that can be made into my own personal library.
*/

#include <string>
#include <iostream>
using namespace std;

#include "Flags.h"

int main()
{
	cout << "Test" << endl;

	Flags flag = Flags::HELLO;

	cout << int(flag) << endl;

	flag &= Flags::MY;

	cout << int(Flags::HELLO) << " &= operation " << int(Flags::MY) << " equals " << int(flag) << endl;

	cout << int(flag) << endl;

	flag |= Flags::NAME;

	cout << " |= operation " << int(flag) << endl;

	flag = Flags::HELLO;

	cout << int(flag) << endl;

	flag <<= Flags(1);

	cout << int(flag) << endl;

	flag = Flags::MY;

	cout << "Begin " << int(flag) << endl;

	flag >>= Flags(1);

	cout << int(flag) << endl;

	flag = Flags::HI;

	cout << "With 0 apply ~ operator " << int(~flag) << endl;

	//char x = 2;

	//x >>= 1;

	//cout << int(x) << endl;

	return 0;
}