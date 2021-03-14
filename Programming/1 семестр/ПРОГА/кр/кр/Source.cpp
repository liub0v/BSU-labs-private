#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX = 100;

void calculate(double [] , char* , int );

void find_and_calculate(char* mas)
{
	
	int n = 0;
	double a[MAX];
	for (int i = 0; i < MAX; i++)
	{

		int ch, zn;
		if (mas[i] == '/')
		{
			int d = 1;
			ch = 0;
			zn = 0;
			int temp = 0;
			for (int j = i - 1; j >= 0; j--) 
			{
				if (((mas[j] >= '0') && (mas[j] <= '9')) || (mas[j] == '-'))
				{
					ch +=(mas[j]-'0')*pow(10,temp);
					temp++;
			
				}
				else break;
			}

			for (int j = i + 1; j < MAX; j++)
			{
				if ((mas[j] >= '0') && (mas[j] <= '9'))
				{
					zn = zn * 10 + (mas[j]-'0');

				}
				else break;
			}
			a[n++] = (double)ch / zn;
		}
	}
	cout << "Âûäåëåííûå ÷èñëà: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;

	calculate(a, mas, n);
}
void calculate(double a[],char* mas,int n)
{
	int element = -1;
	for (int i = 0; i < MAX; i++)
	{
		if (mas[i] == '/')
		{
			element++;
		}

		if (mas[i] == '*') 
		{
			a[element] *= a[element + 1];
			for (int j = element + 1; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			element--;
			n--;
		}
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	cout << endl << "Çíà÷åíèå âûðàæåíèÿ (";
	for (int i = 0; i <=strlen(mas)-1; i++)
	{
		cout << mas[i];
	}
	cout << ") ðàâíî " << sum << endl << endl;

}
void main()
{
	setlocale(LC_ALL, "rus");
	char *mas = new char[MAX];
	for (int i = 0; i < MAX; i++)
	{
		mas[i] = 0;
	}

	ifstream file("FILE.txt");

	if (!file)
	{
		cout << "ÔÀÉË ÍÅ ÍÀÉÄÅÍ!";
		exit(0);
	}

	if (file.peek() == EOF)
	{
		cout << "ÔÀÉË ÏÓÑÒ!";
		exit(0);
	}

	file.getline(mas, MAX);

	find_and_calculate(mas);

	delete[] mas;
	file.close();
	system("pause");
	
}
