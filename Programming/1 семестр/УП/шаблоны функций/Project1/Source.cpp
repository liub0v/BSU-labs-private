#include <iostream>
#include <locale>
#include <iomanip>
#include <math.h>
#include <conio.h>
#include <time.h>
using namespace std;
template <typename type>
int pr(type **a, type b, const int n, const int m)
{
	int k = 0, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) 
			if (a[i][j] == b) k++;
	if (k > 1) return 1;
	else return 0;
};
template <typename type>
type find(type **matr, const int n,const int m)
{
	


	int max;
	max = matr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matr[i][j] > max)
				if (pr(matr, matr[i][j], n,m) == 1)
					max = matr[i][j];
	return max;

};
int main()
{
	setlocale(LC_ALL, "rus");
	const int n = 3;
	const int m = 3;
	cout << "Максимальный размер случайного числа - ";
	int maximum; cin >> maximum; cout << "\n";

	int** matr;
	matr = new int*[n];
	for (int i = 0; i < n; ++i)
		matr[i] = new int[m];

	//ввод матрицы
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//matr[i][j] = rand() % maximum + 1;
			cin >> matr[i][j];
		}
	}

	//вывод матрицы на экран
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "\t";

		for (int j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n  max= " << find(matr, n,m) << endl;
	system("pause");
	return 0;
}










