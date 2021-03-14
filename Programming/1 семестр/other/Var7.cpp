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
	char temp[256];
	while (!f1.eof())
	{
		int count = 0, r = 0;
		f1.getline(temp, 256);
		while (temp[r] != '\0')
		{
			if (temp[r] != ' ' && temp[r+1] == ' ')
			count = r;
			r++;
		}
		if (count!=0)
		count++;
		temp[count] = '\0';
		f2 << temp << endl;
 	}
	return 0;
}