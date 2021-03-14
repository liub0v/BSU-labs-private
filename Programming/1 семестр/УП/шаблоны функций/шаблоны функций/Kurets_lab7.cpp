
/*–азработать шаблон функции, позвол€ющей в заданной матрице
определить максимальное значение из элементов, встречающихс€ более
одного раза.*/


#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//функци€, котора€ находит максимальное значение 

template <typename type>
int pr(type **a, type b, int n, int m)
{
	int k = 0, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (a[i][j] == b) k++;
	if (k > 1) return 1;
	else return 0;
};
template <typename type>
type find(type **mx, int n, int m)
{
	type** a;
	a = new type*[n];
	for (int i = 0; i < n; i++)
		a[i] = new type[n];

	type max;
	max = mx[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mx[i][j] > max)
				if (pr(mx, mx[i][j], n, m) == 1)
					max = mx[i][j];
	return max;

};


// случайные значени€ различных типов:

void get_rand(int & v)
{
	
	v = rand() % 30;//20
}

void get_rand(double & v)
{
	
	v = (rand() % 99) / 30.0;//99, 30.0
}

void get_rand(char * & v)
{
	const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int size = 3;

	char *p = new char[size + 1];
	v = p;
	while (size > 0)
	{
		size--;
		*p = alpha[rand() % 3];//3
		p++;
	}
	*p = '\0';
}

// заполнение матрицы случайными значени€ми

template <class TYPE>
void fill_matrix(TYPE ** & mx, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			get_rand(mx[i][j]);
		}
	}
}

// распечатка матрицы

template <class TYPE>
void output_matrix(TYPE ** mx, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			cout << " \t" << mx[i][j];
		}
		cout << "\n";
	}
}


//освобождение пам€ти дл€ матрицы

template <class TYPE>
void alloc_matrix(TYPE ** & mx, int M, int N)
{
	mx = new TYPE *[M];
	for (int i = 0; i < M; i++)
	{
		mx[i] = new TYPE[N];
	}
}

template <class TYPE>
void free_matrix(TYPE ** & mx, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		delete[] mx[i];
	}
	delete[] mx;
}

template <>
void free_matrix <char *>(char * ** & mx, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			delete[] mx[i][j];
		}
		delete[] mx[i];
	}
	delete[] mx;
}

// основна€ программа 

template <class TYPE>
void do_task(TYPE ** & mx, int M, int N)
{
	alloc_matrix(mx, M, N);//выделение пам€ти
	fill_matrix(mx, M, N);//заполнение матрицы
	cout << "Source matrix: \n";
	output_matrix(mx, M, N);//вывод матрицы
	cout << "MAX is " << find(mx, M, N) << endl;
}

///////////////////////////////////////////////////////

void main()
{
	time_t time_rand_init = time(NULL);
	srand((unsigned)time_rand_init);

	int M = 0, N = 0;
	do
	{
		cerr << "Enter matrix dimentions(for example: 4 6) :\n";
		cin >> M;
		cin >> N;

	} while (M <= 0 || N <= 0);

	cout << "rand() init by: " << time_rand_init << "\n";
	cout << "Matrix dimentions: " << M << "x" << N << "\n";

	cout << "\nMatrix of int: \n";
	int ** mx_int;
	do_task(mx_int, M, N);

	cout << "\nMatrix of double: \n";
	double ** mx_dbl;
	cout << setprecision(2);
	do_task(mx_dbl, M, N);

	cout << "\nMatrix of char *: \n";
	char * ** mx_str;
	do_task(mx_str, M, N);

	system("pause");
	
}




	




		
	

