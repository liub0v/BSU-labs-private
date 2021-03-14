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
	int n;
	fin >> n;
	double *mass = new double[n];
	for (int i = 0; i < n; i++)
	{
		fin >> mass[i];
		fout << mass[i] << " ";
	}
	double buffer;
	for (int i=0; i< n-1;i++)
		for (int g = 1; g < n;g++)
		{
			if (mass[g - 1] > mass[g])
			{
				buffer = mass[g-1];
				mass[g-1] = mass[g];
				mass[g] = buffer;
			}
		}
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		//cout << mass[i] << " ";
		if (mass[i - 1] == mass[i])
			count++;
		if (mass[i - 1] != mass[i] && mass[i - 1] == mass[i - 2])
			count++;
	}
	fout << endl << n-count;
	return 0;
}