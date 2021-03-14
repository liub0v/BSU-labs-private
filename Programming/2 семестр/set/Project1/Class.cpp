#include "Class.h"
#include <string>
#include<iostream>
using namespace std;
struct avto
{
	avto() {};
	avto(int n, string m, int d, int c) { number = n; marka = m; date = d; cost = c; }
	int number;
	string marka;
	int date;
	int cost;
	void input()
	{
		avto ob;
		cin >> ob.number;
		cin >> ob.marka;
		cin >> ob.date;
		cin >> ob.cost;
	};
};
void main()
{
	setlocale(LC_ALL, "rus");
	char n;
	char choose;
	int max;
	cout << "Введите максимальный размер множества";
	cin >> max;
	set <avto> set1(max);
	set <avto> set2(max);
	set <avto> set3(max * 2);
	avto x;
	do {
		cout << '\n'
			<< " ------------Menu------------ "
			<< '\n' << "1. Добавление эл-та в множество"
			<< '\n' << "2. Удаление эл-та из множества"
			<< '\n' << "3. Проверка вхождения эл-та в множество"
			<< '\n' << "4. Присвоение одного множества другому"
			<< '\n' << "5. Пересечение двух множеств"
			<< '\n' << "6. Объединение двух множеств"
			<< '\n' << "7. Разность двух множеств"
			<< '\n' << "8. Вывод множества на экран"
			<< '\n' << "0. Выход"
			<< '\n' << "<";
		cin >> n;
	//	clrscr();
		switch (n)
		{
		case '1':cout << "Выберете множество для добавления(1/2)";
			cin >> choose;
			cout << "Введите э-т";
			x.input();
			if (choose == '1')
				set1.add(x);
			if (choose == '2')
				set2.add(x);
			break;
		case '2':cout << "Выберете множество для удаления(1/2)";
			cin >> choose;
			cout << "Введите величину эл-та";
			x.input();
			if (choose == '1')
				set1.del(x);
			if (choose == '2')
				set2.del(x);
			break;
		case '3':cout << "Выберете множество для проверки(1/2)";
			cin >> choose;
			cout << "Введите величину эл-та";
			x.input();
			if (choose == '1')
			{
				if (set1.check_in(x))
					cout << "Элемент содержится в данном множестве";
				else
					cout << "Элемент не содержится в данном множестве";
			}
			if (choose == '2')
			{
				if (set2.check_in(x))
					cout << "Элемент содержится в данном множеств";
				else
					cout << "Элемент не содержится в данном множестве";
			}
			break;
		case '4':cout << "Выберете в какое множество копировать(1/2)";
			cin >> choose;
			if (choose == '1')
				set1 = set2;
			if (choose == '2')
				set2 = set1;
			break;
		case '5':set3 = set1 * set2;
			cout << "Результат записан в 3е множество";
			break;
		case '6':set3 = set1 + set2;
			cout << "Результат записан в 3е множество";
			break;
		case '7':cout << "Выберете вычитаемое(1/2)";
			cin >> choose;
			if (choose == '1')
				set3 = set1 - set2;
			if (choose == '2')
				set3 = set2 - set1;
			break;
		case '8':cout << "Выберите множество для вывода(1/2/3)";
			cin >> choose;
			if (choose == '1')
				set1.output();
			if (choose == '2')
				set2.output();
			if (choose == '3')
				set3.output();
			break;
		case '0':return;
		default:cout << "Действие не выбрано";
		}
	} while (true);
}