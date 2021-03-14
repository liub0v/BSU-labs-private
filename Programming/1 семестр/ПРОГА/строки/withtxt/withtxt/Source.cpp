//—трока состоит из слов, разделенных одним или несколькими
//пробелами.Ќайти слово, в котором число различных символов
//минимально.≈сли таких слов несколько, найти первое из них.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
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

	const int LEN = 300;
	char str[LEN], temp[LEN] = " ";
	ifstream words("words.txt");
	
	if (!words)
	{
		cout << "no such file\n";
		exit(0);
	}
	int min;
	char *next_token = NULL;
	char del[] = " ,.?!";
	char *token;
	while (words.getline(str, LEN))
	{
		strcpy(temp, "");
		min = LEN - 1;
		token = strtok_s(str, del, &next_token);
		while (token)
		{
			if (Num(token) < min)
			{
				min = Num(token);
				strcpy_s(temp, token);
				
			}
			token = strtok_s(NULL, del, &next_token);
			
		}cout << temp << endl;
	}


	words.close();
	system("pause");

}