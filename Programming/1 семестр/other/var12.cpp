#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	ifstream fin("IN.TXT");
	ofstream fout("OUT.TXT", ios::out);
	if (!fin.is_open())
	{
		cerr << "Файл не найден!" << endl;
		system("Pause");
		return 1;
	}
	if (fin.peek() == EOF)
	{
		cerr << "Файл пуст!" << endl;
		system("Pause");
		return 2;
	}
	int n = 0;
	while (!fin.eof())
	{
		int term = 0;
		fin >> term;
		n++;
	}
	fin.clear();
	fin.seekg(NULL);
	int *massivchik = new int[n];
	int k = 0;
	while (!fin.eof())
	{
		fin >> massivchik[k];
		for (int j = 0; j < k;j++)
		{
			if (massivchik[k] == massivchik[j])
			{
				k--;
				n--;
				break;
			}
		}
		k++;
	}
	k = 0;
	for (int o=0; o < n;o++)
	{
		int a = massivchik[k], size=0;
		while (a != 0)
		{
			a /= 10;
			size++;
		}
		a = massivchik[k];
		int *mass = new int[size];
		for (int i = 0;i < size;i++)
		{
			mass[i] = a % 10;
			a /= 10;
		}
		int buffer;
		for (int i=0;i<size-1; i++)
			for (int j = 1;j < size;j++)
			{
				if (mass[j - 1] > mass[j])
				{
					buffer = mass[j-1];
					mass[j-1] = mass[j];
					mass[j] = buffer;
				}
			}
		fout << massivchik[k] << ":";
		for (int i = 0; i < size; i++)
			fout << mass[i];
		fout << endl;
		delete[] mass;
		k++;
	}
	system("Pause");
	return 0;
}