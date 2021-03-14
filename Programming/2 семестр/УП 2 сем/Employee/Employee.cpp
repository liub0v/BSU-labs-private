#include <iostream>
#include <fstream>
#include "Employee.h"

using namespace std;

Employee * readEmployeeFromFile ( int *n)//ifstream fin,
{
	ifstream fin;
	//fin.open(INPUT_FILE);
	fin.open("input.txt");
	//char str[MAX_LINE_LENGTH];

	//узнаем кол-во сотрудников:
	//int *n;
	fin >> *n;
	fin >> *n;

	cout << n;
	Employee * employeeArr = new Employee[*n]; //динамический массив для кол-ва сотрудников
	for (int i = 0; i < *n; ++i)
	{
		fin >> employeeArr[i].lastName;
		fin >> employeeArr[i].position;
		fin >> employeeArr[i].date.day;
		fin >> employeeArr[i].date.month;
		fin >> employeeArr[i].date.year;
		fin >> employeeArr[i].salary;
	}
	fin.close();
	return employeeArr;
}

void writeEmployeeOnConsole(Employee *employeeArr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << employeeArr[i].lastName;
		cout << employeeArr[i].position;
		cout << employeeArr[i].date.day;
		cout << employeeArr[i].date.month;
		cout << employeeArr[i].date.year;
		cout << employeeArr[i].salary;
	}

}