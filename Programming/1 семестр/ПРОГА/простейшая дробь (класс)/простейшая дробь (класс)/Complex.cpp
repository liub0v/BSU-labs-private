#include"Complex.h"
#include <iostream>

using namespace std;
void Complex :: output(Complex &C)
{
	int ch = C.getch();
	int zn = C.getzn();
	if ((ch > 0 && zn > 0) || (ch < 0 && zn < 0))
	{
		cout << fabs(ch) << "/" << fabs(zn)<<endl;
	}
	else
	{
		if (ch < 0 || zn < 0)
			cout << "-(" << fabs(ch) << "/" << fabs(zn) << ")"<<endl;

		else
		{
			if (ch == 0)
				cout << "0"<<endl;
		}
	}

};
Complex Complex::addition(Complex&C1, Complex&C2)
{
	int ch1 = C1.getch();
	int zn1 = C1.getzn();
	int ch2 = C2.getch();
	int zn2 = C2.getzn();
	if (ch1 == 0 && ch2!=0)
	{
		Complex C1(ch2, zn2);
		return C1;
	}
	if (ch2 == 0 && ch1!=0)
	{
		Complex C2(ch1, zn1);
		return C2;
	}
	int ch = ((ch1*zn2) + (ch2*zn1));
	int zn = zn1 * zn2;
	Complex C(ch, zn);
	return C;
}
Complex Complex::multiplication(Complex&C1, Complex&C2)
{
	int ch1 = C1.getch();
	int zn1 = C1.getzn();
	int ch2 = C2.getch();
	int zn2 = C2.getzn();
	int ch = ch1 * ch2;
	int zn = zn1 * zn2;
	Complex C(ch, zn);
	return C;
}
Complex Complex::division(Complex&C1, Complex&C2)
{
	int ch1 = C1.getch();
	int zn1 = C1.getzn();
	int ch2 = C2.getch();
	int zn2 = C2.getzn();
	int ch = ch1 * zn2;
	int zn = ch2 * zn1;
	Complex C(ch, zn);
	return C;
}
