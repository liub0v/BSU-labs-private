/*построить список данных сотрудников, о сотрудниках есть информация : его должность, зарплата, фамилия, дата принятия на работу;
Найти по фамилии, посчитать среднюю зарплату, вывести список сотрудников, принятых после заданной даты, отсортировать по зарплате и фамилии*/

#include <iostream>
#include "Employee.h"
#include <fstream>

using namespace std;



int main()
{
	//ifstream fin;
	ofstream fout;
	//fin.open(INPUT_FILE);
	//fout.open(OUTPUT_FILE);

	//char str[MAX_LINE_LENGTH];
	
	//узнаем кол-во сотрудников:
	int n;
	//fin>>n;
	Employee* employeeArr;// = new Employee[n]; //динамический массив для кол-ва сотрудников
	employeeArr = readEmployeeFromFile(&n);//(&fin
	writeEmployeeOnConsole(employeeArr, n);
	
	delete[]employeeArr;

	//fout.close();
	system("pause");
	return 0;
}
