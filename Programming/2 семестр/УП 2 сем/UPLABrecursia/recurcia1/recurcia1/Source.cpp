#include <iostream>
using namespace std;
int Rec(int x);
int main()
{

	int x; 
	cout << "Enter x ";
	cin >> x;
	cout << endl;
	cout <<"Sum = "<<Rec(x)<<endl;
	char ch; cout << "Press <Ctrl>+Z to finish..." << endl; cin >> ch;
}
	int Rec(int x)
	{
		static int sum = 0;
		static int div=1;
		do
		{
			if (x%div == 0)
			{
				sum += div;
				div++;
				Rec(x);
			}
			else
				div++;

		} while (div <= x);
		return sum;
			
		
	}
         
