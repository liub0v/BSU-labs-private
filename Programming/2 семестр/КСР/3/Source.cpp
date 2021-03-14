#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
static int i = 5, k = 1;
static double sum = 0;
map<pair<double, int>, int> map_;

void map__(void)
{
	map_.insert(make_pair(make_pair(sum, k), i));
	i += 2;
}

int main()
{
	double e = 0.000001, eps = 0.0000001;
	double res = 0;
	int hun = 100;

	_asm
	{
		begin_:
		finit
		fldln2
		fstp res
		while_begin :
		fld res
			fsub sum
			fabs
			fld e
			fxch st(1)
			fcomip  st, st(1)
			jb while_end
			finit

			
			fild k
			fld1
			fdiv st, st(1)
			test k, 1
			
			jz    even_
			jnz   odd_
			even_ : 
		    fchs
				odd_ :

			fld sum
			fadd
			fstp sum
			inc k
			jmp while_begin
			while_end :
			call map__
				fld e
				fld eps
				fcomip  st, st(1)
				jae end_
				fild hun
				fxch st(1)
				fdiv  st, st(1)
				fstp e
				jmp begin_
				end_ :
	}
	cout << "Assembler: \n";
	cout << "RESULT = " << setprecision(9) << res << "\n";

	for (auto iter : map_)
	{
		cout << "The number of iterations to find " << iter.second << " correct numbers after the decimal point:" << iter.first.second << endl;
			
	    cout<< "res: " << iter.first.first << endl;
	}

	system("pause");
	return 0;
}