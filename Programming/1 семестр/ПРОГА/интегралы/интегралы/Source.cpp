#include <cmath>
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double f(double x) {

	return 1 / (1 + sqrt(x));
}

int main() {

	const int N = 1000; 
	

	double a, b;
	do {
		cout << "Enter the interval of integration through the gap: ";
		cin >> a >> b;
	} while (a >= b);
	double dx1 = (m - k) / (n - 1);
	for (double x = k; x < (m + dx1 / 2); x += dx1) s1 += F(x) * dx1;
	

	double dx = (b - a) / (N - 1);
	double sum = 0;
	for (double x = a; x < (b + dx / 2); x += dx)
		sum += dx * f(x);
	cout << "Method rectangles: " << sum << endl;

	

	

	cout << "The exact value: " << b * b * b - a * a * a << endl;

	system("pause");
}