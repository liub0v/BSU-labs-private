#include <iostream>
#include <fstream>

using namespace std;

void PushBack(char *&Oper, int &SOper, double *&Doub, int &SDoub) {
	if (Oper[SOper - 1] == '-') {
		SOper--;
		Doub[SDoub - 1] = -Doub[SDoub - 1];
		return;
	}
	SDoub--;
	double x = Doub[SDoub--], y = Doub[SDoub];
	SOper--;
	char c = Oper[SOper];
	if (c == '+') Doub[SDoub++] = x + y;
	else Doub[SDoub++] = x * y;
}

double is_oper(char x) {
	return x == '-' || x == '+' || x == '*';
}

int Priority(char x) {
	if (x == '-') return 3;
	if (x == '*') return 2;
	if (x == '+') return 1;
	if (x == '(') return 0;
}

void InFile() {
	ifstream cin("in.txt");
	if (!cin || !cout) {
		cout << "there is no file in.txt!\n";
		system("pause");
		exit(1);
	}
	while (cin.peek() != EOF) {
		char *array = new char[100];
		char *OperandStack = new char[100];
		double *DoubleStack = new double[100];
		int SizeOperand = 0, n, SizeDouble = 0, i = 0;
		for (int i = 0; i < 100; i++) array[i] = 0;
		cin >> array; cin.ignore();
		for (n = 0; array[n] != 0; n++);
		cout << array << '\n';
		while (i<n) {
			if (array[i] == ')') {
				while (OperandStack[SizeOperand - 1] != '(') PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
				SizeOperand--;
				i++;
			}
			if (array[i] == '(') {
				OperandStack[SizeOperand++] = array[i];
				i++;
			}
			if (array[i] > 47 && array[i] < 58) {
				char *x = new char[100];
				char *y = new char[100];
				int sz1 = 0, sz2 = 0;
				for (; i < n && array[i] > 47 && array[i] < 58; x[sz1++] = array[i], i++);
				i++;
				for (; i < n && array[i] > 47 && array[i] < 58; y[sz2++] = array[i], i++);
				double X = atof(x), Y = atof(y);
				DoubleStack[SizeDouble++] = X / Y;
			}
			if (is_oper(array[i])) {
				while (SizeOperand>0 && Priority(OperandStack[SizeOperand - 1]) >= Priority(array[i])) PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
				OperandStack[SizeOperand++] = array[i];
				i++;
			}
		}
		while (SizeOperand>0) PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
		cout <<DoubleStack[0] << "\n\n";
	}
	cin.close();
}

void NotInFile() {
	cout << "Enter e to exit\n";
	char *array = new char[100];
	for (int i = 0; i < 100; i++) array[i] = 0;
	cin >> array; cin.ignore();
	while (array[0]!='e') {
		char *OperandStack = new char[100];
		double *DoubleStack = new double[100];
		int SizeOperand = 0, n, SizeDouble = 0, i = 0;
		for (n = 0; array[n] != 0; n++);
		cout << array << '\n';
		while (i<n) {
			if (array[i] == ')') {
				while (OperandStack[SizeOperand - 1] != '(') PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
				SizeOperand--;
				i++;
			}
			if (array[i] == '(') {
				OperandStack[SizeOperand++] = array[i];
				i++;
			}
			if (array[i] > 47 && array[i] < 58) {
				char *x = new char[100];
				char *y = new char[100];
				int sz1 = 0, sz2 = 0;
				for (; i < n && array[i] > 47 && array[i] < 58; x[sz1++] = array[i], i++);
				i++;
				for (; i < n && array[i] > 47 && array[i] < 58; y[sz2++] = array[i], i++);
				double X = atof(x), Y = atof(y);
				DoubleStack[SizeDouble++] = X / Y;
			}
			if (is_oper(array[i])) {
				while (SizeOperand>0 && Priority(OperandStack[SizeOperand - 1]) >= Priority(array[i])) PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
				OperandStack[SizeOperand++] = array[i];
				i++;
			}
		}
		while (SizeOperand>0) PushBack(OperandStack, SizeOperand, DoubleStack, SizeDouble);
		cout << DoubleStack[0] << "\n\n";
		for (int i = 0; i < 100; i++) array[i] = 0;
		cin >> array; cin.ignore();
	}
}

int main() {
	cout << "Work with files? y/n\n";
	char InType;
	cin >> InType;
	if (InType == 'y') InFile(); 
	else NotInFile();
	bool NowOperand = false;
	system("pause");
}