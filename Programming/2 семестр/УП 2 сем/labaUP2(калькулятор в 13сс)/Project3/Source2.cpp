#include<iostream>
using namespace std;
int main()
{
	char znak; // знак операции
	unsigned v1, v2, result; // операнды и результат
		cout << "Enter operation( +, - ,* , / ). Quit - q: ";
		cin >> znak;
		if (znak == 'q') return 0;
		cout << "Enter operands: ";
		cin >> v1 >> v2;
		if (!cin.good()) // если введены некорректные данные, посылаем
		{
			cerr << " Illegal data ! " << endl;
			return 1;
		}// сообщение об ошибке и
		// завершаем работу прграммы
		int result1 = 0;
		int result2 = 0;
		int cnt = 0;
		while (v1 > 0)
		{
			result1 += v1 % 10 * pow(13, cnt++);
			v1 /= 10;
		}
		cnt = 0;
		while (v2 > 0)
		{
			result2 += v2 % 10 * pow(13, cnt++);
			v2 /= 10;
		}
		
		switch (znak)
		{
		case'+': result = result1 + result2; break;
		case'-': result = result1 - result2; break;
		case'*': result = result1 * result2; break;
		case'/':
			if (result2 != 0) result = result1 / result2;
			else { cerr << "Division by zero!" << endl; result = 0xffffffff; }
			break;
		default: { cerr << "Illegal operation: " << znak << endl; result = 0; }
		}
		if (int(result) < 0)
			result = result*-1;
		char ostatok;
		while (result > 0)
		{
			ostatok = result % 13;
			result /= 13;
			switch (ostatok)
			{
			case 10: ostatok = 'A'; break;
			case 11: ostatok = 'B'; break;
			case 12: ostatok = 'C'; 
			}
			if (ostatok <= 9)
				cout << int(ostatok);
			else
				cout << ostatok;
		}
		cout << endl;
		system("pause");
	
}