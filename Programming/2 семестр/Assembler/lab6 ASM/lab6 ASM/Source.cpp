#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

extern "C" string _stdcall spaceasm(string S, string E);

int main()
{
	string S, E;
	S = "We have a string, who haves a     maaany     spaces";
	E = " ";
	string D = spaceasm(S, E);
	cout << D;
	system("pause");
	return 0;
}