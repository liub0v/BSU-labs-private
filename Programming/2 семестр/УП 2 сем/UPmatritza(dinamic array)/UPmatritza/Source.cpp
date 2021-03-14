#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, m, i, j, temp, y;
	cout << "Введите кол-во строк матрицы:";
	cin >> n;
	cout << "Введите кол-во столбцов матрицы:";
	cin >> m;
	int **Matrica = new int*[n];
	for (i = 0; i < n; i++)
	{
		Matrica[i] = new int[m];
		for (j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "]= ";
			cin >> Matrica[i][j];
			if (Matrica[i][j] > 0)
				int first = i;
		}
	}
	cout << "Исходная матрица:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << Matrica[i][j] << "  ";
		cout << endl;
	}



	for (i = 0; i < n; i++)
	{
		temp = 0;
		for (j = 0; j < m; j++)
			if (Matrica[i][j] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (y = i; y < n - 1; y++)
				for (j = 0; j < m; j++)
					Matrica[y][j] = Matrica[y + 1][j];
			n--;
			i--;
		}
	}
	for (i = 0; i < m; i++)
	{
		temp = 0;
		for (j = 0; j < n; j++)
			if (Matrica[j][i] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (y = i; y < m - 1; y++)
				for (j = 0; j < n; j++)
					Matrica[j][y] = Matrica[j][y + 1];
			m--;
			j--;
		}
	}


	cout << endl;
	cout << "Полученая матрица:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << Matrica[i][j] << "  ";
		cout << endl;
	}
	system("pause");
	return 0;
}