#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;


const int N = 100;


int main()
{
	setlocale(LC_ALL, "rus");
	
	char *c = new char[N];
	for (int i = 0; i < N; i++) {
		c[i] = ' ';
	}

	ifstream fin("input.txt");

	if (!fin)
	{
		cout << "No file";
		system("pause");
		return 1;
	}

	if (!fin.getline(c, N))
	{
		cout << "File is emty";
		system("pause");
		return 1;
	}
	
	//проверка на корректность введенных символов
	for (int i = 0; i < N; i++) {
		if (c[i] != ' ' && c[i]!='/' && c[i] != '\0' && c[i] != '.' && c[i] != '*' && c[i] != '+' && c[i] != '-' && c[i] != '(' && c[i] != ')' && (c[i] < '0' || c[i] > '9')) {
			cout << "В записи присутствуют некорректные символы" << endl;
			return 0;
		}
	}
	
	int cnt = 0;
	double a[N];
	for (int i = 0; i < N; i++) {
		if (c[i] == '/') {
			int ii = i + 1, t = 1;
			int znam = 0;
			do {
				znam += (c[i + 1] - '0')*t; // собираем знаменатель 
				t * 10;
				ii++;
			} while ((ii >= 0) && (c[ii] >= '0') && (c[ii] <= '9'));

			int ij = i - 1;
			int chisl = 0;
			
			do {
				chisl += (c[i - 1] - '0')*t; // собираем числитель
				t * 10;
				ij--;
			} while ((ij >= 0) && (c[ij] >= '0') && (c[ij] <= '9'));
		
			a[cnt++] = (double)chisl/znam;
			
		}
	}
	cout << "Числа из последовательности: ";
	for (int i = 0; i < cnt; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
	
	int uk = -1;
	for (int i = 0; i < N; i++) {


		if (c[i] == '/') {
			uk++;
		}

		if (c[i] == '*') { //нашли операцию умножения, она предназначена для элементов с номерами uk и (uk + 1)
			a[uk] *= a[uk + 1];  
			for (int j = uk + 1; j < cnt; j++) {
				a[j] = a[j + 1]; 

			}
			uk--;   
			cnt--; 
		}
	}

	double sum = 0.0;
	for (int i = 0; i < cnt; i++) {
		sum += a[i];
	}


	// найдем позицию в массиве символов где заканчивается выражение
	int pos = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (c[i] != '\0' && c[i] != ' ') {
			pos = i;
			break;
		}
	}

	// вывод результата

	for (int i = 0; i <= pos; i++) {
		cout << c[i];
	}
	cout << " = " << sum << endl;


	delete[] c;
	fin.close();
	system("pause");
	return 0;
}
