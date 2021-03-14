#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("IN.TXT");
	ofstream fout("OUT.TXT", ios::out);
	if (!fin.is_open())
	{
		cerr << "Файл не найден!";
		return 1;
	}
	if (fin.peek() == EOF)
	{
		cerr << "Файл пуст!";
		return 2;
	}
	int n = 0;
	fin >> n;
	double *mass = new double[n];
	for (int i = 0; i < n;i++)
	{
		fin >> mass[i];
	}
	int LeftM = 0, RightM = 0, R = 0, L = 0;
	for (int i = 0; i < n;i++)
	{
		L = R = i;
		while (mass[i] < mass[i + 1]&&i < n)
			i++;
		R = i;
		if (R - L > RightM - LeftM)
		{
			RightM = R;
			LeftM = L;
		}
	}
	for (int i = 0; i < n;i++)
	{
		fout << mass[i]<< " ";
	}
	fout << endl;
	if (RightM - LeftM == 0)
		cerr << "Последовательностей нет!" << endl;
	else
		for (int i = LeftM; i <= RightM;i++)
			fout << mass[i] << " ";
	return 0;
}