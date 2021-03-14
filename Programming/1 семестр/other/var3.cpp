#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	setlocale(0, "");
	ifstream f1("IN.TXT");
	ofstream f2("OUT.TXT", ios::out);
	if (!(f1.is_open()))
	{
		cerr << "Файл не найден!" << endl;
		system("pause");
		return 1;
	}
	if (f1.eof())
	{
		cerr << "Файл пуст!" << endl;
		system("pause");
		return 2;
	}
	int N = 0;
	f1 >> N;
    bool *inf = new bool[N]();
	int *mass = new int[N];
	for (int i = 0; i < N; i++)
	{
		f1 >> mass[i];
	}
	int count = 0;
	for (int i = 1; i < N-1;i++)
	{
		if (mass[i] < mass[i - 1] && mass[i] < mass[i + 1])
		{
			inf[i] = true;
			count++;
		}
	}
	if (mass[0] < mass[1]) 
	{
		inf[0] = true;
		count++;
	}
	if (mass[N - 1] < mass[N - 2])
	{
		inf[N-1] = true;
		count++;
	}
	f2 << count << endl;
	for (int i = 0; i < N;i++)
	{
			f2 << mass[i] << ' ';
	}
	f2 << endl;
	for (int i = 0; i < N;i++)
	{
		if (inf[i] == true)
			f2 << i << ' ';
	}
}