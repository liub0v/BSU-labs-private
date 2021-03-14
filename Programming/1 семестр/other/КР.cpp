#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


const int MAX = 100;
void find(char* mas)
{
	int n = 0;
	double a[MAX];
	for (int i = 0; i < MAX; i++)
	{
		if (mas[i] == '/')
		{
			int j = i + 1, tmp = 1;
			int zn = 0;
			do {
				zn += (mas[i + 1] - '0')*tmp; // собираем знаменатель 
				tmp * 10;
				j++;
			} while ((j >= 0) && (mas[j] >= '0') && (mas[j] <= '9'));

			int k = i - 1;
			int ch = 0;

			do {
				ch += (mas[i - 1] - '0')*tmp; // собираем числитель
				tmp * 10;
				k--;
			} while ((k >= 0) && (mas[k] >= '0') && (mas[k] <= '9'));

			a[n++] = (double)ch / zn;

		}
	}
	cout << "Числа, выделенные из последовательности  ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

int main()
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
		cout << "No such file";
		return 1;
	}

	if (file.peek() == EOF)
	{
		cout << "File is emty";
		return 1;
	}
	
	find(mas);
	
	int element = -1;
	for (int i = 0; i < MAX; i++)
	{
		if (mas[i] == '/') 
		{
			element++;
		}

		if (mas[i] == '*') //нашли операцию умножения, она предназначена для элементов с номерами uk и (uk + 1)
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

	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}


	// найдем позицию в массиве символов где заканчивается выражение
	int pos = 0;
	for (int i = MAX - 1; i >= 0; i--)
	{
		if (mas[i] != '\0' && mas[i] != ' ')
		{
			pos = i;
			break;
		}
	}

	// вывод результата

	for (int i = 0; i <= pos; i++) 
	{
		cout << mas[i];
	}
	cout << " = " << sum << endl;


	delete[] mas;
	file.close();
	system("pause");
	return 0;
}
