/*Тесты

Введите строку слов через пробелы длиною не больше80
5,3 5.2 6,2 ыа54п
5.3
6.2

*/


#define CRT_NO_WARNINHS
#include<iostream>
#include<string>
#include<string.h>
#define MAX_LEN 80
using namespace std;
int SumCel(double a);
double *ToDoubleMass(const char *str,int  &mass_size) {
	double*mass_double = new double[strlen(str) /2 +1];
	char* temp = new char[strlen(str) + 1];
	int  temp_i = 0,i=0, mass_i=0;
	char* end;
	while (i < strlen(str))
	{
		while (str[i] == ' ')
		{
			i++;
		}
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == '-')
		{
			temp[temp_i] = str[i];
			temp_i++;
			i++;
		}
		temp[temp_i++] = '\0';
		temp_i = 0;
		if (str[i] == '\0' || str[i] == ' ')
		{
			strtod(temp, &end);
			if (*end == '\0') {
				mass_double[mass_i] = strtod(temp, &end);
				mass_i++;
			}
		}
		else {
			while (str[i] != ' ' && i < strlen(str))
			{
				i++;
			}
		}
	}
	double t = 0; mass_i--;
	for (int i = mass_i; i>0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (SumCel(mass_double[j])>SumCel(mass_double[j+1]))
			{
				t = mass_double[j];
				mass_double[j] = mass_double[j + 1];
				mass_double[j + 1] = t;
			}
		}
	}
	mass_size = (mass_i+1);
	return mass_double;
}



int SumCel(double a) {
	int b=floor(a);
	int sum = 0;
	while (abs(b)>0)
	{
		sum += b % 10;
		b = b / 10;
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, ".1251");
	char* str = new char[MAX_LEN];
	int mass_size = 0;
	double*mass_double = new double[MAX_LEN/2];
	cout << "Введите строку слов через пробелы длиною не больше" << MAX_LEN << endl;
	cin.get(str, MAX_LEN);
	mass_double = ToDoubleMass(str,mass_size);
	for (int i = 0; i < mass_size; i++)
	{
		cout << mass_double[i] << '\n';
	}
	system("pause");
	return 0;
}