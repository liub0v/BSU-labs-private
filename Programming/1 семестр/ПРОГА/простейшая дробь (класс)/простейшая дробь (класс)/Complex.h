#pragma once
class Complex
{
	int ch, zn;
public:
	Complex(int ch, int zn) : ch(ch), zn(zn) {}
	int getch()
	{
		return ch;
	}
	
	int getzn()
	{
		return zn;
	}
	Complex() {};
	Complex(const Complex &C) : ch(C.ch), zn(C.zn){}
	void output (Complex &C);
	Complex addition(Complex&C1, Complex&C2);
	Complex multiplication(Complex&C1, Complex&C2);
	Complex division(Complex&C1, Complex&C2);

};
