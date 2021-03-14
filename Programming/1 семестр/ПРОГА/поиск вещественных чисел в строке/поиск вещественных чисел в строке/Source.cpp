//поиск вещественных чисел в строке 
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

void main()
{
	char st[100], sl[100];

	cin.getline(st,100);

	int n = strlen(st);

	
	for (int i = 1; i < n; i++)
	{
		int h = 0;
		int l = 0;


		if (st[i] == '.')
		{
			for (int j = i - 1; j >= 0; j--)
				if (((st[j] >= '0') && (st[j] <= '9')) || (st[j] == '-')) h++; else break;

			if (h > 0)
				for (int j = i + 1; j < n; j++)
					if ((st[j] >= '0') && (st[j] <= '9')) l++; else break;
			if (l > 0)
				for (int j = i - h; j < i + l + 1; j++)
					cout << st[j];

			cout << endl;
		}


	}
	system("pause");
}