#include"Complex.h"
#include <iostream>

using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	int ch1,zn1;
	cout << "Введите значение числителя: ";
	cin >> ch1;
	while(true)
	{
		cout << "Введите значение знаменателя: ";
		cin >> zn1;
		if (zn1 != 0)
		{
			break;
		}
		cout << "Ошибка. Знаменатель не может быть равен нулю." << endl;
	}
	int ch2, zn2;
	cout << "Введите значение числителя: ";
	cin >> ch2;
	while (true)
	{
		cout << "Введите значение знаменателя: ";
		cin >> zn2;
		if (zn2 != 0)
		{
			break;
		}
		cout << "Ошибка. Знаменатель не может быть равен нулю." << endl;
	}
	Complex C1(ch1, zn1), C2(ch2, zn2);
	Complex C3,C4,C5;
	C3 = C3.addition(C1, C2);
	C4 = C4.multiplication(C1, C2);
	C5 = C5.division(C1, C2);

	Complex output;
	cout << "Первая дробь: ";
	output.output(C1);
	cout << "Вторая дробь: ";
	output.output(C2);
	cout << "Результат сложения дробей: ";
	output.output(C3);
	if (ch1 == 0 || ch2 == 0)
	{
		cout << "Результат умножения дробей: 0"<<endl;
	}
	else
	{
		cout << "Результат умножения дробей: ";
		output.output(C4);
	}
	if (ch2 != 0)
	{
		cout << "Результат деления дробей: ";
		output.output(C5);
	}
	else 
	{
		cout << "Pезультата деления нет, так как на ноль делить нельзя" << endl;;
	}


	system("pause");
}