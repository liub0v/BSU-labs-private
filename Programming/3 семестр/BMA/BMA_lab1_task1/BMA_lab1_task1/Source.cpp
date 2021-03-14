#include <iostream>
#include <iomanip>
static int count_numb = 0;
using namespace std;

#include <ctime>
#include<vector>
#include<algorithm>

//¬ычисление определител€ матрицы
float Det(float** Matrix, int size)
{
	float det = 1;
	for (int i = 0; i < size; i++)
	{
		det = det * Matrix[i][i];

	}
	if (count_numb % 2 != 0)
	{
		det = det * (-1);
	}
	return det;
}
// обратный ход
float* find_roots(float** Matrix, float* Answ, int size)
{
	float* X = new float[size];
	for (int row = size - 1; row >= 0; row--)
	{
		for (int column = size - 1; column >= row; column--)
		{
			if (row == column)
			{
				try {
					if (Matrix[row][column] == 0)
					{
						throw(-1);
					}
				}
				catch (int s)
				{
					cout << "нет ответа";
					exit(-1);
				}

				X[column] = Answ[row] / Matrix[row][column]; //xn=bn/cnn
			}
			else
			{
				Answ[row] = Answ[row] - X[column] * Matrix[row][column];
			}
		}
	}
	return X;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int size;
	cout << "–азмер матрицы: ";
	cin >> size;                                              
	float** Matrix = new float* [size];
	float** Matrix_temp = new float* [size];
	float** Matrix_en = new float* [size];
	float** Matrix_reverse = new float* [size];
	float* Answ = new float[size];
	float* Answ_temp = new float[size];
	float* Roots = new float[size];
	for (int i = 0; i < size; i++)
	{
		Matrix[i] = new float[size];
		Matrix_en[i] = new float[size];
		Matrix_temp[i] = new float[size];
		Matrix_reverse[i] = new float[size];
		Answ[i] = 0;
	}
	 // заполнение матрицы
	for (int i = 0; i < size; i++)                                 
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				Matrix_en[i][j] = 1;
			}
			else {
				Matrix_en[i][j] = 0;
			}
			Matrix[i][j] = (rand() % 2200 - 1100) / 100.0;
			Matrix_temp[i][j] = Matrix[i][j];

		}
		Roots[i] = (rand() % 2200 - 1100) / 100.0;

	}
	//вычисление вектора f
	
	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			Answ[row] = Answ[row] + Matrix[row][column] * Roots[column];
			Answ_temp[row] = Answ[row];
		}

	}

	cout << "A|f" << endl;   //вывод матрицы


	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			if (column + 1 == size)
			{
				cout << setw(10) << Matrix[row][column] << "|";
			}
			else {
				cout << setw(10) << Matrix[row][column] << "";
			}
		}
		cout << setw(10) << Answ[row] << endl;
	}

	cout << "X:";   //вывод корней

	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << Roots[i] << " ";
	}
	//пр€мой ход

	bool temp;
	float div;
	for (int k = 0; k < size; k++) // матрица ј с помощью элементарных преобразований приводитс€ к нижне треугольной
	{
		//выбор главного по столбцу, переставл€ем строки марицы так, 
		//чтобы наиб по мод элемент при xk попал на глав диагональ
		//потом выбираем его как глав элемент
		for (int row = k; row < size; row++)  
		{
			if (abs(Matrix[row][k]) > abs(Matrix[k][k]))
			{
				swap(Matrix[row], Matrix[k]);
				swap(Answ[row], Answ[k]);
				count_numb++;
			}
		}
		/*ƒалее исключим переменную из всех уравнений, начина€ с
		(k + 1).ƒл€ этого вычтем получившуюс€ после перестановки k 
			строку из остальных строк, домножив еЄ на величину, равную
			отношению  элемента каждой из этих строк к k элементу
			первой строки, обнул€€ тем самым столбец под ним.*/
		for (int row = k + 1; row < size; row++)
		{
			div = Matrix[row][k];
			temp = true;
			for (int col = k; col < size; col++)
			{
				if (Matrix[k][k] == 0)
				{
					temp = false;
					continue;
				}
				Matrix[row][col] = Matrix[row][col] - Matrix[k][col] * div / Matrix[k][k];
			}
			if (temp == true)
			{
				Answ[row] = Answ[row] - Answ[k] * div / Matrix[k][k];
			}
		}
	}


	cout << endl;
	cout << "Det: ";                           //нахождение определител€
	float det = Det(Matrix, size);
	cout << det << endl;
	cout << endl;




	float* X;


	X = find_roots(Matrix, Answ, size);                     //нахожение корней
	cout << "–ешени€:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << X[i] << " ";
	}
	cout << endl;



	//вычисление обратной матрицы

	for (int i = 0; i < size; i++)
	{
		float* En = Matrix_en[i];
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				Matrix[row][col] = Matrix_temp[row][col];
			}
		}

		for (int k = 0; k < size; k++)                 //приводим к ниже треугольной
		{

			for (int row = k; row < size; row++)
			{
				if (abs(Matrix[row][k]) > abs(Matrix[k][k]))
				{
					swap(Matrix[row], Matrix[k]);
					swap(En[row], En[k]);
				}
			}
			for (int row = k + 1; row < size; row++)
			{
				div = Matrix[row][k];
				temp = true;
				for (int col = k; col < size; col++)
				{
					if (Matrix[k][k] == 0)
					{
						temp = false;
						continue;
					}
					Matrix[row][col] = Matrix[row][col] - Matrix[k][col] * div / Matrix[k][k];
				}
				if (temp == true)
				{
					En[row] = En[row] - En[k] * div / Matrix[k][k];
				}
			}
		}
		float* Temp;
		Temp = find_roots(Matrix, En, size);                                      

		for (int j = 0; j < size; j++)
		{
			Matrix_reverse[j][i] = Temp[j];
		}


	}

	cout << "A^(-1)" << endl;

	for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			cout << setw(12) << Matrix_reverse[row][column] << " ";
		}
		cout << endl;
	}

	// A*A^(-1)
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			Matrix[row][col] = 0;
		}
	}

	for (int A_row = 0; A_row < size; A_row++)
	{
		for (int col = 0; col < size; col++)
		{
			for (int row = 0; row < size; row++)
			{
				Matrix[A_row][col] = Matrix[A_row][col] + Matrix_temp[A_row][row] * Matrix_reverse[row][col];
			}
		}
	}
	cout << "A*A^(-1)" << endl;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cout << setw(12) << Matrix[row][col] << " ";
		}
		cout << endl;
	}
	float x = 0;
	vector<float> v;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			x = x + Matrix_temp[row][col] * X[col];
		}
		v.push_back(Answ_temp[row] - x);
		x = 0;
	}

	sort(v.begin(), v.end());
	cout << "ћаксимум-норма нев€зки" << endl;
	cout << abs(v[v.size() - 1]) << endl;
	v.clear();

	for (int i = 0; i < size; i++)
	{
		v.push_back(X[i] - Roots[i]);
	}
	sort(v.begin(), v.end());
	cout << "ћаксимум-норма погрешности" << endl;
	cout << abs(v[v.size() - 1]);
}


