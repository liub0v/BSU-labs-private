#include <iostream>
#include <iomanip>
#include <ctime>
#include<vector>
#include<algorithm>
using namespace std;


float* roots(float* alfa, float* beta, int size)
{
	float* y = new float[size];

	y[size - 1] = beta[size];


	for (int i = size - 2; i >= 0; i--)
	{
		y[i] = alfa[i + 1] * y[i + 1] + beta[i + 1];
	}
	return y;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int size;
	cout << "Размер матрицы" << endl;
	cin >> size;                                                
	float** Matrix = new float* [size];

	float* y = new float[size];
	float* f = new float[size];
	float* a = new float[size];
	float* c = new float[size];
	float* b = new float[size - 1];

	float* alf = new float[size];
	float* bet = new float[size + 1];

	for (int i = 0; i < size; i++)
	{
		Matrix[i] = new float[size];
		f[i] = 0;
	}


	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			Matrix[row][column] = 0;
		}
	}

	
	for (int i = 0; i < size; i++)                              
	{
		for (int j = 0; j < size; j++)
		{
			if (j == i + 1 || i - 1 == j)
			{
				Matrix[i][j] = (rand() % 2200 - 1100) / 100.0;
			}
		}
		y[i] = (rand() % 2200 - 1100) / 100.0;
	}

	for (int i = 0; i < size; i++)                                
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				if (i == 0)
				{
					if (rand() % 2 + 1 == 1)
					{
						Matrix[i][j] = -(abs(Matrix[i][j + 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
					else {
						Matrix[i][j] = (abs(Matrix[i][j + 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
				}

				else if (i == size - 1) {
					if (rand() % 2 + 1 == 1)
					{
						Matrix[i][j] = -(abs(Matrix[i][j - 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
					else
					{
						Matrix[i][j] = (abs(Matrix[i][j - 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
				}
				else
				{
					if (rand() % 2 + 1 == 1)
					{
						Matrix[i][j] = -(abs(Matrix[i][j + 1]) + abs(Matrix[i][j - 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
					else
					{
						Matrix[i][j] = (abs(Matrix[i][j + 1]) + abs(Matrix[i][j - 1]) + abs((rand() % 2200 - 1100) / 100.0));
					}
				}


			}
		}
	}

	cout << endl;



	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			f[row] = f[row] + Matrix[row][col] * y[col];
		}

	}

	cout << "A|f" << endl;


	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (col + 1 == size)
			{
				cout << setw(10) << Matrix[row][col] << "|";
			}
			else {
				cout << setw(10) << Matrix[row][col] << "";
			}
		}
		cout << setw(10) << f[row] << endl << endl;
	}

	cout << "X" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << y[i] << " ";
	}

	cout << endl;

	// распределяем по векторам

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (row == col)
			{
				c[row] = Matrix[row][col];
			}
			if (row + 1 == col)
			{
				b[row] = -Matrix[row][col];
			}
			if (row - 1 == col)
			{
				a[row] = -Matrix[row][col];
			}
		}
	}
	//проверка на устойчивость и корректность

	try {
		if (abs(c[0]) == 0 || abs(c[size - 1]) == 0 || abs(b[0]) == 0 || abs(a[size - 1]) == 0 || abs(c[0]) < abs(b[0]) || abs(c[size - 1]) < abs(a[size - 1]))
			throw(-1);
	}
	catch (int s)
	{
		cout << "нет ответа";
		exit(-1);
	}

	for (int i = 1; i < size - 1; i++)
	{
		try {
			if (abs(a[i]) == 0 || abs(b[i]) == 0 || abs(c[i]) < abs(a[i]) + abs(b[i]))
				throw(-1);
		}
		catch (int s)
		{
			cout << "нет ответа";
			exit(-1);
		}
	}

	bool ind = false;
	for (int i = 1; i < size; i++)
	{
		if (abs(c[i]) > abs(a[i]) + abs(b[i]))
			ind = true;
	}
	if (abs(c[0]) > abs(b[0]) || abs(c[size - 1]) > abs(b[size - 1]))
	{
		ind = true;
	}

	try {
		if (ind == false)
		{
			throw(-1);
		}
	}
	catch (int s)
	{
		cout << "нет ответа";
		exit(-1);
	}


	bool temp;
	float div;
	float mul;
	//вычисление по формулам 
	//прямой ход
	alf[1] = b[0] / c[0];
	bet[1] = f[0] / c[0];
	for (int i = 1; i < size - 1; i++)
	{
		alf[i + 1] = b[i] / (c[i] - alf[i] * a[i]);;
		bet[i + 1] = (f[i] + a[i] * bet[i]) / (c[i] - alf[i] * a[i]);
	}
	bet[size] = (f[size - 1] + a[size - 1] * bet[size - 1]) / (c[size - 1] - alf[size - 1] * a[size - 1]);


	float* X;

	//обратный ход
	X = roots(alf, bet, size);                     //находим корни
	cout << "Answers" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << X[i] << " ";
	}

	cout << endl;

	float x = 0;
	vector<float> v;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			x = x + Matrix[row][col] * X[col];
		}
		v.push_back(f[row] - x);
		x = 0;
	}

	sort(v.begin(), v.end());
	cout << "Максимум-норма невязки" << endl;
	cout << abs(v[v.size() - 1]) << endl;
	v.clear();

	for (int i = 0; i < size; i++)
	{
		v.push_back(X[i] - y[i]);
	}
	sort(v.begin(), v.end());
	cout << "Максимум-норма погрешности" << endl;
	cout << abs(v[v.size() - 1]);
}


