#include <iostream>
#include <cstring>
using namespace std;

int Num(char *str)
{
	int len = strlen(str);
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		bool done = true;
		for (int j = 0; j < len; j++)
		{
			if (i != j && str[i] == str[j])
			{
				done = false;
				break;
			}
		}
		if (done)
			++k;
	}
	return k;
}

void main()
{
	int n;
	const int LEN = 300;
	char word[LEN], temp[LEN] = " ";
	cout << "The nomber of words = ";
	cin >> n;
	int min = LEN - 1;
	for (int i = 0; i < n; i++)
	{
		cout << "Word: ";
		cin >> word;
		if (Num(word) <= min)
		{
			min = Num(word);
			strcpy_s(temp, word);
		}
	}
	cout << temp << endl;
	system("pause");
	
}