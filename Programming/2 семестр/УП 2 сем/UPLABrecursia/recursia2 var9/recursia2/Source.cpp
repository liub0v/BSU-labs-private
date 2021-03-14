#include <iostream>
#include <assert.h>
using namespace std;
int rec(int*mas, int n)
{
	static int i = 1;
	static int max = mas[0];
	assert(n > 2);
	do
	{
		if (mas[i] > max)
		{
			max = mas[i];
			i++;
			rec(mas, n);
		}
		i++;
		
	} while (i < n);
	return max;
	
}
void main()
{
	int *mas;
	int n;
	cout << "enter the number of elements in the array ";
	cin >> n;
	mas = new int[n];
	cout << "enter elements\n";
	for (int i = 0; i < n; ++i)
		cin >> mas[i];
	cout <<"max = "<< rec(mas, n)<<endl;
	delete mas;
	char ch; cout << "Press <Ctrl>+Z+<Enter> to finish..." << endl; cin >> ch;
}