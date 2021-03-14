#include "Money.h"
#include<iostream>

using namespace std;

Money :: Money(long long   pounds, long long   shillings, long long   pence) : farthings(getFarthings(pounds, shillings, pence))
{
	setlocale(LC_ALL, "rus");
	errors();
	long long   newPounds = 0;
	long long   newShillings = 0;
	long long  newPence = 0;

	get(newPounds, newShillings, newPence);

	if (newPounds != pounds || newShillings != shillings || newPence != pence)
	{
		cerr << "Введены некорректные данные" << endl;
		system("pause");
		exit(0);
		
	}
}

Money::Money(const Money&  pounds) : farthings(pounds.farthings) {}

Money&   Money::operator= (const Money&  pounds)
{
	farthings = pounds.farthings;
	return  *this;
}

Money  Money::operator- () const
{
	Money  money;
	money.farthings = -farthings;
	return  money;
}

Money&  Money::operator+= (const Money&  pounds)
{
	farthings += pounds.farthings;
	errors();
	return  *this;
}

Money&  Money::operator-= (const Money&  pounds)
{
	return  operator+=(-pounds);
}

Money  Money::operator+ (const Money&  pounds) const
{
	Money  money(*this);
	return  money += pounds;
}

Money  Money::operator- (const Money&  pounds) const
{
	return  operator+(-pounds);
}

bool  Money::operator== (const Money&  pounds) const
{
	return  farthings == pounds.farthings;
}

bool  Money::operator< (const Money&  pounds) const
{
	return  farthings < pounds.farthings;
}

ostream& operator<< (ostream& os, Money p)
{
	if (p < 0)
	{
		os << "-";
		p = -p;
	}

	long long   pounds = 0;
	long long   shillings = 0;
	long long   pence = 0;

	p.get(pounds, shillings, pence);

	if (pounds)
	{
		os << pounds << "pd.";
	}

	if (shillings)
	{
		os << shillings << "sh.";
	}

	if (!pounds && !shillings || pence)
	{
		os << pence << "p.";
	}

	return os;
}

void  Money::errors() const
{
	setlocale(LC_ALL, "rus");
	if (farthings < 0)
	{
		cerr << "Отрицательное значение!" << endl;
		
		
	}

	if (farthings > FARTHINGS_MAX)
	{
		cerr << "Слишком большое значение!" << endl;
	}
}

long long  Money::getFarthings(long long   pounds, long long   shillings, long long   pence)
{
	return FARTHINGS * (pence + (PENCE * (shillings + SHILLINGS * pounds)));
}

void  Money::get(long long&  pounds, long long&  shillings, long long&  pence)  const
{
	pence = farthings / FARTHINGS;

	shillings = pence / PENCE;
	pence = (int)pence % PENCE;

	pounds = shillings / SHILLINGS;
	shillings = shillings % SHILLINGS;
}

