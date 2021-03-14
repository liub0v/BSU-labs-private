#include<iostream> 
#include <math.h> 
#include <iomanip> 
using namespace std;


double f1(double x) {

	return 1 / (1 + sqrt(x));
}

double f2(double x) {

	return sqrt(pow(2, x) - 1);
}

double f3(double x) {

	return asin(sqrt(x)) / sqrt(x*(1 - x));
}


double INT1(int a, int b, double eps, double(*F)(double)) 
{ 

	double n = 1;
	double s1 = 1;
	double s2 = 2;
	while (abs(s1 - s2) > eps)
	{
		{
			double dx1 = (b - a) / n;
			s1 = (F(b))*dx1;
			for (int i = 1; i <= n - 1; ++i) s1 += F(a + dx1 * i) * dx1;

			double dx2 = (b - a) / (n + 1);
			s2 = (F(b))*dx2;
			for (int i = 1; i <= n; ++i) s2 += F(a + dx2 * i) * dx2;
		}
		++n;
	}
	return s2;
}

double INT2(double a, int b, double eps, double(*F)(double)) 
{ 

	double n = 1; 
	double s1 = 1;
	double s2 = 2;
	while (abs(s1 - s2) > eps)
	{
		{
			double dx1 = (b - a) / n;
			s1 = (F(b))*dx1;
			for (int i = 1; i <= n - 1; ++i) s1 += F(a + dx1 * i) * dx1;

			double dx2 = (b - a) / (n + 1);
			s2 = (F(b))*dx2;
			for (int i = 1; i <= n; ++i) s2 += F(a + dx2 * i) * dx2;
		}
		++n;
	}
	return s2;
}


double INT3(double a, double b, double eps, double(*F)(double)) 
{ 

	double n = 1; 
	double s1 = 1;
	double s2 = 2;
	while (abs(s1 - s2) > eps)
	{
		{
			double dx1 = (b - a) / n;
			s1 = (F(b))*dx1;
			for (int i = 1; i <= n - 1; ++i) s1 += F(a + dx1 * i) * dx1;

			double dx2 = (b - a) / (n + 1);
			s2 = (F(b))*dx2;
			for (int i = 1; i <= n; ++i) s2 += F(a + dx2 * i) * dx2;
		}
		++n;
	}
	return s2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	 

	const int A1 = 0;
	const int B1 = 2;
	const double EPS1 = 0.00000001; //0.000000001;
	cout<< "Первый интеграл = ";
	cout<<  INT1(A1, B1, EPS1, f1);
	cout<< endl;

	const double A2 = 0.2;
	const int B2 = 1;
	const double EPS2 = 0.00000001;//0.000000001;
	 
	cout<< "Второй интеграл = ";
	cout<<  INT2(A2, B2, EPS2, f2);
	cout<< endl;

	const double A3 = 0.2;
	const double B3 = 0.3;
	const double EPS3 = 0.0000000001;

	cout<< "Третий интеграла = ";
	cout<<  INT3(A3, B3, EPS3, f3);
	cout<< endl;
	
	
	system("pause");
	return 0;
}