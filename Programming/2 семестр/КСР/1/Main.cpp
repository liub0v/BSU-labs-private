#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

extern "C" void _cdecl funk(double);


double f(double x)
{
	return -3*x*x - 1.7/(x+11) + 5.2;
}


double ep_root(double a, double b, double e)
{
	double c;
	while (fabs(b - a) > e)      
	{
		c = (a + b) / 2;        
		if (f(c) >= 0)   
			a = c;            
		else
			b = c;            
	}
	return (a + b) / 2.0;   
}


int main()
{
	double e, x;
	cout << "-3x^2-1.7/(x+11)+5.2=0"<<endl;
	cout << "Enter the accuracy: ";
	cin >> e;        
	x = ep_root(-10, 10, e);  
	cout << "C++: "<< setprecision(9) << x << "\n";
	
	int eleven = 11;
	double a1 = -10, a2 = 10, res = 0;
	double a = -3, b = -1.7, c = 5.2;

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
			fld1
			fld1
			fadd
			fld a1
			fadd a2
			fdiv st, st(1)
			fst res

			fld b
			fild eleven
			fld c
			fld a
			call funk
			fldz
			fxch st(1)
			fcomip st, st(1)
			
			jb     less_
			fld res
			fstp a1
			jmp    both
			less_:
		    fld res
			fstp a2
			both:

			jmp while_begin
				while_end :
			finit
				fld1
				fld1
				fadd
				fld a1
				fadd a2
				fdiv st, st(1)
				fst res
	}
	cout << "Assembler: "<< res << "\n";  

	system("pause");
	return 0;
}
