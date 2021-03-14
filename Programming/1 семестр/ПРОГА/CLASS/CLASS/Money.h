#pragma once
#include <iostream>
using namespace std;

class  Money
{
	static const long long  SHILLINGS = 20;
	static const long long  PENCE = 12;
	static const long long  FARTHINGS = 4;
	static const long long  POUNDS_MAX = 1000000000;
	static const long long  FARTHINGS_MAX = FARTHINGS * PENCE * SHILLINGS * POUNDS_MAX;
	long long   farthings;

	void  errors() const;
	static long long  getFarthings(long long   pounds, long long   shillings, long long   pence);
	void  get(long long&  pounds, long long&  shillings, long long &  pence) const;

public:

	Money (long long   pounds = 0, long long   shillings = 0, long long    pence = 0);

	Money (const Money&  pounds);

	Money& operator=(const Money&  pounds);
	Money operator-() const;
	Money& operator+=(const Money& pounds);
	Money& operator-=(const Money& pounds);
	Money operator+(const Money& pounds) const;
	Money operator-(const Money& pounds) const;
	bool operator==(const Money& pounds) const;
	bool operator<(const Money& pounds) const;
	friend  ostream& operator<< (ostream& os, Money p);

};
