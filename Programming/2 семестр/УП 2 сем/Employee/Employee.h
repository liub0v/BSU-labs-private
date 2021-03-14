#pragma once
#include <fstream>
//const char* INPUT_FILE = "input.txt";
//const char* OUTPUT_FILE = "output.txt";
//const int MAX_LINE_LENGTH = 100;
struct Date
{
	int day;
	int month;
	int year;
};

struct Employee
{
	char lastName[30];//фамилия
	char position[30];//должность
	Date date;
	int salary;//зарплата
};

Employee * readEmployeeFromFile (int *n);
void writeEmployeeOnConsole (Employee *employeeArr, int n);