#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, res;
	int i;
	cout << "2^x:" << endl;
	cout << "x = ";
	cin >> x;

	_asm
	{
		xor ebx, ebx
		mov eax, 1
		finit
		fld x

		fld1
		fld     st(1)
		fprem  // Остаток от деления на единицу даст дробную часть
		fsub    st(2), st // Если вычесть её из исходного числа, получится целая часть
		fxch    st(2)
		fldz
		fcomip  st, st(1)
		jb next_
		fabs
		mov ebx, 1
		next_:
		fistp i
		
		mov ecx, i
		jecxz no_for
		dec ecx
		mov eax, 2
		jecxz no_for
		for_ :
		shl eax, 1
			loop for_
			no_for :
		
			fxch    st(1)
			f2xm1
			fadd 
            mov i, eax
            fild i
				cmp ebx, 0
				je mul_
				fld1
				fdiv st, st(1)
				fmul st, st(2)
				jmp end_
				mul_:
            fmul
				end_:
			fstp res
	}

	cout << "RESULT: "<< setprecision(9) << res << endl;  

	system("pause");
	return 0;
}