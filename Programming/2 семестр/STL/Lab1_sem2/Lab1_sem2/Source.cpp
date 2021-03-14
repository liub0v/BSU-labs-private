#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int element_sum(vector<vector<int>>::iterator i)
{
	int sum = 0;
	for (vector<int>::iterator j = i->begin(); j != i->end(); ++j)
		sum += *j;
	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int max_element;
	cout << "Введите максимальное значение " << endl;
	cin >> max_element;
	int n, m;
	cout << "Введите количество строк и столбцов матрицы " << endl;
	cin >> n;
	cin >> m;

	vector<vector<int>> V(n);
	 
	for (int i = 0; i < n; ++i)
	{
		V[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			V[i][j] = rand() % (max_element + 1);
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << V[i][j] << " ";
		}
		cout << endl;
	}

	int MAX = -1;
	vector<vector<int>>::iterator itI;
	int itJ;
	for (vector<vector<int>>::iterator i = V.begin(); i != V.end(); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i->at(j) > MAX)
			{
				MAX = i->at(j);
				itI = i;
				itJ = j;
			}
		}
	}
	
	V.erase(itI);
	for (vector<vector<int>>::iterator i = V.begin(); i != V.end(); ++i)
	{
		i->erase(i->begin() + itJ);
	}

	cout << "Измененная матрица:\n";
	for (vector<vector<int>>::iterator i = V.begin(); i != V.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
			cout << *j << " ";
		cout << endl;
	}

	for (vector<vector<int>>::iterator i = V.begin(); i != V.end(); ++i)
	{
		for (vector<vector<int>>::iterator j = i + 1; j != V.end(); ++j)
		{
			if (element_sum(i) > element_sum(j))
				swap(*i, *j);
		}
	}

	cout << "Отсортированная матрица: \n";
	for (vector<vector<int>>::iterator i = V.begin(); i != V.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++)
			cout << *j << " ";
		cout << endl;
	}

	
	system("pause");
	return 0;
}