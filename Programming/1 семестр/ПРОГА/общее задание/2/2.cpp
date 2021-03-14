/* форматирует строку вида xxxx258aaaa xxxx0x102aaaa переводит число в 16-ричную сс*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <locale>
using namespace std;
void changeLine(char*str)
{
	char *firstpart;
	firstpart = new char[strlen(str)];
	char *lastpart;
	lastpart = new char[strlen(str)];
	int n = 0;
	for (int i = 0; i <= strlen(str); ++i)
		firstpart[i] = 0;
	for (int i = 0; i < strlen(str); ++i)
		lastpart[i] = 0;
	for (int j = 0; j <= strlen(str); ++j)
	{
		if (str[j] > '0' && str[j] <= '9')
		{
			while (str[j] > '0' && str[j] <= '9')
			{
				n = n * 10 + str[j] - 48;
				++j;
			}
		}
		if (n == 0)
		{
			static int i = 0;
			firstpart[i] = str[j];
			++i;
		}
		if (n != 0)
		{
			static int i = 0;
			lastpart[i] = str[j];
			++i;
		}
	}

	for (int i = 0; i < strlen(firstpart); ++i)
		cout << firstpart[i];
	printf("%X", n);
	for (int i = 0; i < strlen(lastpart); ++i)
		cout << lastpart[i];
	cout << endl;


}
void main()
{
	char *str;
	str = new char[100];
	cout << "Enter the line(like aaaaa128xxxx): " << endl;
	cin >> str;
	cout << "Received line: " << endl;
	changeLine(str);
	system("pause");

}