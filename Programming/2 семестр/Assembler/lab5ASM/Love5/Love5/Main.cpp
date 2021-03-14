
#include <iostream>
#include <ctime>
using namespace std;

const int sz = 3;

void print_int(int n)
{
	cout << n << " ";
}

extern "C" int _fastcall TestFast(int,int, int[sz][sz]);
extern "C" int _stdcall TestStd(int, int, int[sz][sz]);
extern "C" int _cdecl TestCdecl(int, int, int[sz][sz]);


int main()
{
	int
		m,
		n,
		hlp,
		a[sz][sz],
		res = 1,
		i = 0;

	//srand(time(0));
	n = sz;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 100 + 40;


	cout << "Matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}

	//TestFast(n, res, a);
	//TestStd(n, res, a);
	TestCdecl(n, res, a);
	
	_asm
	{

		/*mov n, ebx
		mov i, ecx
		mov edx, [eax]
		mov m, edx*/

		mov res, eax
		
	}
	
	cout << "Composition = " << res << endl;

	
	system("Pause");
	exit(0);
	return 0;
}