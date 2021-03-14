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
	while (!fin.eof())
	{
		int buf = 0;
		fin >> buf;
		n++;
	}
	int *mass = new int[n];
	fin.clear();
	fin.seekg(NULL);
	int k = 0;
	while (!fin.eof())
	{
		fin >> mass[k];
		for (int j = 0; j < k; j++)
		{
			if (mass[k] == mass[j])
			{
				k--;
				n--;
			}
		}
		k++;
	}
	for (int i = 0; i <n; i++)
	{
		int count = 0, n=mass[i]-1;
		while (n != 0)
		{
			if (mass[i]%n == 0)
			{
				count += n;
			}
			n--;
		}
		if (count == mass[i])
			fout << mass[i] << ":perfect" << endl;
		if (count> mass[i])
			fout << mass[i] << ":abundant" << endl;
		if (count < mass[i])
			fout << mass[i] << ":deficient" << endl;
	}
	return 0;
}