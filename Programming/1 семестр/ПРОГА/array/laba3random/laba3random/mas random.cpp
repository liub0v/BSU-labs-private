#include <iostream>
#include <time.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	const int N = 100;
	int mas[N];
	int n;
	while (true)
	{
		cout << "enter n  ";
		cin >> n;
		if (n > 0)
			break;
		cout << "Введены некорректные данные\n";
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		mas[i] = 1 + rand() % n;
	int min = abs(mas[0]);
	for (int i = 1; i < n; i++)
	{
		if (min > abs(mas[i]))
			min = mas[i];
	}
	cout << "Минимальный по модулю элемента массива: " << min << endl;
	///////////////////////////////////////////////////////////////
	int zero = 0, sum = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] == 0)
		{
			zero = i;
			for (int i = zero; i < n; i++)
				sum += mas[i];
			cout << "Cумма элементов после последнего нулевого" << sum << endl;
		}
	if (zero == 0)
		cout << "Нулевых элементов нет" << endl;
	////////////////////////////////////////////////////////////////
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			cout << " " << mas[i] << " ";
	for (int i = 0; i < n; i++)
		if (i % 2 == 1)
			cout << " " << mas[i] << " ";

	cout << endl;
	system("pause");
}