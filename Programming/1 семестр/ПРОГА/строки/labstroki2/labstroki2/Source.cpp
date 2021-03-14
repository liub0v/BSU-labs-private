#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Num(char *str)
{
	int length = std::strlen(str);
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		bool flag = true;
		for (int j = 0; j < length; j++)
		{
			if (i != j && str[i] == str[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			++k;
	}
	return k;
}

int main()
{
	char *element = new char[64];
	char *element1 = new char[64];
	char *word = new char[64];

	//string word1;

	ifstream words("words.txt");
	if (!words)
	{
		cout << "no such file\n";
		exit(0);
	}

	char *next_token = NULL;
	char del[] =" ";
	words.getline(word, 64);
	words.close();
	
	cout << word << endl;
	int j = 0, g = 0, min = INT_MAX, g1 = 0;


	do 
	{
		
		if (word[j] != ' ')
		{ 
			element[g] = word[j];
			g++;
			cout << "  " << element << endl;
		}
		else
		{

			cout << " NUM " << Num(element);
			if (Num(element) < min)
			{
				cout << " MIN " << min;
				min = Num(element);
				for (int i = 0; i < g; i++)
					element1[i] = element[i];
				cout << "Element1    :    " << element1 << endl;
				g1 = g;
			}
			
			g = 0;
			//j++;
		}
		j++;
		cout << " MIN " << min << " " << g << endl;
		cout << "  " << element1 << endl;
	} while (word[j] != NULL);
	
	

	for (int i = 0; i < g; i++)
		cout << element1[j]<< " ";
	cout << endl;
	cout << element1 << endl;

	
	system("pause");
	return 0;
}