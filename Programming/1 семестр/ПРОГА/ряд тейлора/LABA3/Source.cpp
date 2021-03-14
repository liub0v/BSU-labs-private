#include <iostream>
using namespace std;
void main()
{
	const int MAX = 100;
	setlocale(LC_ALL, "rus");
	double x, k;
	
	while (true)
	{
		cout << "Введите значение х ( х принадлежит промежутку (-1;1] )\n"; // сделать проверку
		cin >> x;
		if (x>-1 && x<=1)
			break;
			cout << "Введены некорректные данные. Повторите попытку)\n"; 
	}
	while (true)
	{
		cout << "Введите значение K (K натуратьлое число большее 1)\n";
		cin >> k;
		if (k>1)
			break;
			cout << "Введены некорректные данные. Повторите попытку)\n";
	}
	
	double ch = x, y = 0;
	double e;
	e = 1/(pow(10, k));
	int n;
	for ( n=2;(fabs(ch) > e) && (n<MAX); ++n)
	{
		ch *= (x*(n - 1) / n)*-1;
		y += ch;
	}
	y = y + x;
	cout << "Значение функции=" << y << " при " << n << " операциях\n";
	double sravnenie;
	sravnenie = log(1 + x);
	cout << "Приближенное значение по формуле ln(1+x) = " << sravnenie << endl;
	system("pause");
}