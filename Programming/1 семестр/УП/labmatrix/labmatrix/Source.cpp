#include <iostream>
using namespace std;
void setItem(int**mas, int n, int i, int j, int value)
{
	if (i + j < n)
		mas[i][j] = value;
}
int getItem(int**mas, int n, int i, int j)
{
	if (i + j < n)
		return mas[i][j];
	else
		return mas[n - 1 - i][n - 1 - j];
}


void main()
{
	setlocale(LC_ALL, "rus");
	int **matrix;
	int n;
	while (true) 
	{
		cout << "Введиет количестко строк и столбцов матрицы ";
		cin >> n;
		if (n > 1 && n <= 10)
			break;
		cout << "Неверно введена размерность массива. Повторите попытку\n";
	}
	matrix = new int*[n]; //выделение памяти под столбцы
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n - i];//под строки но с каждым разом на ячейку меньше
	int value;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n - i; ++j)
		{
			cout << "[" << i << "],[" << j << ']' << endl;
			cin >> value;
			setItem(matrix, n, i, j, value);
		}
	cout << "Исходная матрица:" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << getItem(matrix, n, i, j) << " ";
		cout << endl;
	}
	bool otric; otric = true;
	int mult = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			if (getItem(matrix, n, i, j) < 0)
			{
				otric = false;
				break;
			}
		if (otric)
			for (int j = 0; j < n; ++j)
				mult *= getItem(matrix, n, i, j);
		if (otric)
		{
			cout << "Строка номер " << i << " не сождержит отрицательных элементов, призведение её элементов равно " << mult << endl;
			mult = 1;
		}
		else
		{
			cout << " Строчка " << i << " содержит отрицательные элементы" << endl;
			otric = true;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int s;
	s = matrix[0][n - 1];
	int t1, t2;
	for (int i = 1; i < n; i++)
	{
		t1 = t2 = 0;
		for (int j = 0; j < n - i; j++)
		{
			int k = i + j;
			t1 +=getItem(matrix, n, i+j, j);//matrix[i + j][j];
			t2 +=getItem(matrix, n, j, i+j);// matrix[i][i + j];
		}
		if (t1 < s) s = t1;
		if (t2 < s) s = t2;
	}
	cout << "Минимум суммы элементов диагонали = " << s <<endl;
	system("pause");
}



	

