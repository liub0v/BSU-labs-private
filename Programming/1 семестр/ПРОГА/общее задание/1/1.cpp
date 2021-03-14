/*Выделение целых чисел и сортировка*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <locale>
using namespace std;

void qs(int *items, int left, int right)
{
	register int i, j;
	int x, y;

	i = left; j = right;
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
void quick(int *items, int count)
{
	qs(items, 0, count - 1);
}
void find_and_sort(char *str)
{
	char *words;
	int count = 0;
	int*mas = new int[300];
	words = strtok(str, " ,");
	for (int i = 0; i < 300; i++)
		mas[i] = 0;

	while (words)
	{
		for (int j = 0; j <= strlen(words); j++)
			if (words[j] > '0' && words[j] <= '9')
			{
				while (words[j] > '0' && words[j] <= '9')
				{
					mas[count] = mas[count] * 10 + words[j] - 48;

					j++;
				}
				count++;
			}
		words = strtok(NULL, " ,");

	}
	quick(mas, count);
	for (int i = 0; i < count; ++i)
		cout << mas[i] << " ";
	cout << endl;
	delete[]mas;
}
void main()
{
	ifstream file("words.txt");
	if (!file)
	{
		cout << "no such file\n";
		exit(0);
	}
	char str[300];
	file.getline(str, 300);
	cout << "Sorted array: ";
	find_and_sort(str);
	system("pause");
}