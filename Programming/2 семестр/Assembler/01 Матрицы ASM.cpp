#include <iostream>
#include <iomanip>

using namespace std;

extern "C"	void __fastcall Function1(int, int**, int);

int main()
{
	int a_size, result;
	cin >> a_size;
	int** a = new int*[a_size];
	for (int i = 0; i < a_size; i++)
	{
		a[i] = new int[a_size];
		for (int j = 0; j < a_size; j++)
		{
			a[i][j] = rand() % 1000 - 800;
		}
	}

	cout << endl;
	for (int i = 0; i < a_size; i++)
	{
		for (int j = 0; j < a_size; j++)
		{
			cout << setw(5) << a[j][i] << ' ';
		}
		cout << endl;
	}

	__asm
	{
		mov		eax, -1000000
		mov		ebx, a
		mov		esi, 0
		cycle1:
		mov		edx, -1000000

			mov		ecx, a_size
			cycle2 :
		mov		edi, dword ptr[ebx + 4 * esi]
			cmp		edx, dword ptr[edi + 4 * ecx - 4]
			jg		continue_cycle2
			mov		edx, dword ptr[edi + 4 * ecx - 4]
			continue_cycle2 :
			loop	cycle2

			cmp		edx, 0
			jg		positive_in_column
			cmp		eax, edx
			jg		not_update
			mov		eax, edx
			not_update :
	positive_in_column:
		inc		esi
			cmp		esi, a_size
			jz		break_cycle1
			jmp	cycle1
			break_cycle1 :
		mov		result, eax
	}

	cout << result << endl;
	system("pause");
	return 0;
}