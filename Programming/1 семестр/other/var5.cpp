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
	char temp[256];
	int size = 0;
	int max_num = 0, r=0;
	while (!f1.eof())
	{
		f1 >> temp;
		if (strlen(temp) > size)
		{
			size = strlen(temp);
			max_num = r;
		}
		r++;
	}
	f1.seekg(NULL);
	//r = 0;
	while (!f1.eof())
	{
		f1 >> temp;
	    f2 << temp << ' ';
		//r++;
	}
	f1.seekg(NULL);
	r = 0;
	f2 << endl;
	while (!f1.eof())
	{
		f1 >> temp;
		if (r != max_num)
			f2 << temp << ' ';
		r++;
	}
	f1.close();
	f2.close();
	return 0;
}