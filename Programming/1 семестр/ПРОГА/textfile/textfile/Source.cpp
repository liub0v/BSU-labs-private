#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("IN.TXT");
	ofstream fout("OUT1.TXT", ios::out);
	ofstream fout1("OUT2.TXT", ios::out);
	if (!fin.is_open())
	{
		cerr << "Файл не найден!";
		system("Pause");
		return 1;
	}
	if (fin.peek() == EOF)
	{
		cerr << "Файл пуст!";
		system("Pause");
		return 2;
	}
	while (!fin.eof())
	{
		int count = 0;
		char temp[256];
		fin.getline(temp, 256);
		int size = strlen(temp);
		for (int i = 1; i <= size; i++)
		{
			if (temp[i] == ' ' && temp[i - 1] != ' ' || temp[i] == '\0' && temp[i - 1] != ' ')
			{
				count++;
			}
		}
		if (count <= 2)
		{
			fout1 << temp << endl;
		}
		else
		{
			fout << temp << endl;;
		}
	}
	return 0;
}