#include "Money.h"
#include <iomanip>
#include <string>
using namespace std;

long long  inputMoney(const string & str)
{
	cout <<str<< ": ";
	long long   money;
	cin >> money;
	return  money;
}
Money  input(const string & str)
{
	cout << str << endl;

	long long   pd = inputMoney("‘унты");
	long long   sh = inputMoney("Ўиллинги <20");
	long long  p = inputMoney("ѕенсы <12");

	return  Money(pd, sh, p);
}

int main()
{
	setlocale(LC_ALL, "rus");

	try
	{
		Money money = input("¬ведите количество денег:");

		cout << "«начение с минусом: " << -money << endl;
	}
	catch (exception& e)
	{
		cout << e.what() <<endl;
	}

	cout << "ќперации +, -, +=, -=, ==, <." << endl;

	try
	{
		Money    M1 = input("¬ведите количество денег");
		cout <<endl;

		Money    M2 = input("¬ведите количество денег");
		cout << endl;

		if (M1 == M2)
		{
			cout << M1 << " == " << M2<< endl;
		}
		else if (M1 < M2)
		{
			cout << M1 << " < " << M2 << endl;
		}
		else
		{
			cout << M1<<" > "<< M2<< endl;
		}

		cout << M1 << " + " << M2 << " = ";
		cout << (M1 + M2)<< endl;

		cout << M1 << " - " << M2 << " = ";
		cout << (M1 - M2)<< endl;
	}
	catch (exception&  e)
	{
		cout << e.what()<< endl;
	}
	system("pause");
}