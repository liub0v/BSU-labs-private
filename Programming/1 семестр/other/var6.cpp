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
	//int n = 0;
	/*while (!fin.eof())
	{
		char temp[256];
		fin.getline(temp,256);
		n++;
	}
	fin.clear();
	fin.seekg(NULL);*/
	while (!fin.eof())
	{
		char mass[256];
		fin.getline(mass, 256);
		int first, last;
		int size = strlen(mass);
		for (int i = 0;i < size;i++)
		{
			if (mass[i] == ' ' && mass[i - 1] != ' ')
			{
				first = i;
				break;
			}
		}
		for (int i = size-1;i > 0;i--)
		{
			if (mass[i] == ' ' && mass[i - 1] != ' ')
			{
				last = i + 1;
				break;
			}
		}
		for (int i = last; i < size; i++)
			fout << mass[i];
		for (int i = first; i < last; i++)
			fout << mass[i];
		for (int i = 0;i < first; i++)
			fout << mass[i];
		fout << endl;
	}
	system("Pause");
	return 0;
}