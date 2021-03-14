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
	int n=0;
	while (!fin.eof())
	{
		int temp = 0;
		fin >> temp;
		n++;
	}
	fin.clear();
	fin.seekg(NULL);
	int *mass = new int[n];
	int i = 0;
	while (!fin.eof())
	{
		fin >> mass[i];
		for (int j = 0; j < i;j++)
		{
			if (mass[i] == mass[j])
			{
				i--;
				n--;
				//break;
			}
		}
		i++;
	}
	for (int i = 0; i < n;i++)
	{
		int num = mass[i], per=0;
		while (num != 0)
		{
			int temp;
			temp = num % 10;
			per += temp;
			per *= 10;
			num /= 10;
		}
		fout << mass[i] << ":" << per/10 << endl;
	}
	system("Pause");
	return 0;
}