#include<iostream>
#include <math.h>
#include <iomanip>
#define _USE_MATH_DEFINES

using namespace std;

double integ(double k, double m, double t, double(*F)(double));

extern "C" void _cdecl f(double);

double h(double x) {

	return sin(x*x) + 5*x;
}

double integ(double k, double m, double t, double(*F)(double)) { // a,b - границы интегрирования, n - число точек

	double n = 1;                                                     // f - подынтегральная функция
	double a1 = 1;
	double a2 = 2;
	while (abs(a1 - a2) > t)
	{
		{
			double dx1 = (m - k) / n;
			a1 = (F(k) + F(m))*dx1 / 2;
			for (int i = 1; i <= n - 1; ++i) a1 += F(k + dx1 * i) * dx1;

			double dx2 = (m - k) / (n + 1);
			a2 = (F(k) + F(m))*dx2 / 2;
			for (int i = 1; i <= n; ++i) a2 += F(k + dx2 * i) * dx2;
		}
		++n;
	}
	return a2;
}


int main()
{
	
	const double beg = 0;
	const double end = 2*3.1415;
	const double e = 0.000001; // 
	cout << "integral sin(x^2)+5*x" << endl;
	cout << "C++: "<< setprecision(9) << integ(beg, end, e, h) << "\n";

	int i = 1, n = 1;
	double a1 = 1, a2 = 2, mid1, mid2, tmp;
	int five = 5;

	_asm
	{
		finit
		while_begin :
		fld a1
			fsub a2
			fabs
			fld e
			fxch st(1)
			fcomip  st, st(1)
			jbe while_end
			finit

			fild n
			fld end
			fsub beg
			fdiv st, st(1)
			fst mid1

			fild five
			fld beg
			call f
			fstp tmp
			fld end
			call f
			fld tmp
			fadd
			fld mid1
			fmul
			fld1
			fld1
			fadd
			fxch st(1)
			fdiv st, st(1)
			fstp a1

			mov ecx, n
			dec ecx
			push ecx
			jecxz no_for
			for_1 :
		    finit
            fild five
            fld mid1
            fild i
			fmul
            fld beg
            fadd
			call f
			fld mid1
			fmul
				fld a1
				fadd
				fstp a1
			inc i
		loop for_1
				no_for:
			pop ecx
            mov i, 1

				finit
				fild n
				fld1
				fadd
				fld end
				fsub beg
				fdiv st, st(1)
				fst mid2

				fild five
				fld beg
				call f
				fstp tmp
				fld end
				call f
				fld tmp
				fadd
				fld mid2
				fmul
				fld1
				fld1
				fadd
				fxch st(1)
				fdiv st, st(1)
				fstp a2

				mov ecx, n
				push ecx
				for_2 :
			finit
				fild five
				fld mid2
				fild i
				fmul
				fld beg
				fadd
				call f
				fld mid2
				fmul
				fld a2
				fadd
				fstp a2
				inc i
				loop for_2
				pop ecx
				mov i, 1

				inc n
		jmp while_begin
			while_end :
		
	}

	cout << "Assembler: " << a2 << endl; 

	system("pause");
	return 0;
}