#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "List.h"
#include <string>
//#include "Visitor.h"
#include "Header.h"

using namespace std;

int O = 0;

int main() {
	cout << "1)int\n2)char*\n3)Cars list\n";
	int y;
	cin >> y;
	try {
		switch (y) {
		case 1: {
			bool br = false;
			Set <int, Increase> L;
			while (1) {
				cout << "1.add 2.delete 3.clear 4.get 5.out 6.min\n7.max\n8.imin\n9.imax\n";
				cin >> y;
				switch (y) {
				case 1: {
					cout << "Enter number:\n";
					int x;
					cin >> x;
					L.put(x);
					break;
				}
				case 2: {
					cout << "Enter number:\n";
					int x;
					cin >> x;
					L.del(x);
					break;
				}
				case 3: {
					L.Clear();
					break;
				}
				case 4: {
					int y;
					cout << "Enter number:\n";
					cin >> y;
					cout << L[y];
					break;
				}
				case 5: {
					for (auto x = L.begin(); x != L.end(); ++x) cout << *x << '\n';
					cout << '\n';
					break;
				}
				case 6: {
					MinVisitor<int, Increase> x;
					L.accept(x);
					break;
				}
				case 7: {
					MaxVisitor<int, Increase> x;
					L.accept(x);
					break;
				}
				case 8: {
					IMinVisitor<int, Increase> x;
					L.accept(x);
					break;
				}
				case 9: {
					IMaxVisitor<int, Increase> x;
					L.accept(x);
					break;
				}
				default: {br = true; }
				}
				if (br) break;
			}
			break;
		}
				break;
		case 2: {
			bool br = false;
			Set <char*, Decay> L;
			while (1) {
				cout << "\n1.add\n2.delete\n3.clear\n4.get\n5.out\n6.min\n7.max\n8.imin\n9.imax\n";
				cin >> y;
				switch (y) {
				case 1: {
					cout << "Enter string:\n";
					char* x = new char[20];
					cin.ignore();
					cin.getline(x, 20);
					L.put(x);
					break;
				}
				case 2: {
					cout << "Enter string:\n";
					char* x = new char[20];
					cin.ignore();
					cin.getline(x, 20);
					L.del(x);
					break;
				}
				case 3: {
					L.Clear();
					break;
				}
				case 4: {
					int y;
					cout << "Enter number:\n";
					cin >> y;
					cout << L[y];
					break;
				}
				case 5: {
					for (int i = 0; i < L.Size; i++) cout << L[i] << '\n';
					cout << '\n';
					break;
				}
				case 6: {
					MinVisitor<char*, Decay> x;
					L.accept(x);
					break;
				}
				case 7: {
					MaxVisitor<char*, Decay> x;
					L.accept(x);
					break;
				}
				case 8: {
					IMinVisitor<char*, Decay> x;
					L.accept(x);
					break;
				}
				case 9: {
					IMaxVisitor<char*, Decay> x;
					L.accept(x);
					break;
				}
				default: {br = true; }
				}
				if (br) break;
			}
			break;
		}
		case 3: {
			bool br = false;
			Set <avto, Increase> L;
			while (1) {
				cout << "\n1.add\n2.delete\n3.clear\n4.get\n5.out\n7.min\n8.max\n9.imin\n10.imax\n";
				cin >> y;
				switch (y) {
				case 1: {
					cout << "Enter Number of the car: ";
					int number;
					string data;
					char* brand;
					cin >> number;
					cout << "Enter Data: ";
					cin >> data;
					cout << "Enter Brand of the car: ";
					brand = new char[20];
					cin.ignore();
					cin.getline(brand, 20);
					avto x(number, data, brand);
					L.put(x);
					break;
				}
				case 2: {
					cout << "Enter Number of the car: ";
					int num;
					string data;
					char* Name;
					cin >> num;
					cout << "Enter Data: ";
					cin >> data;
					cout << "Enter Brand of the car: ";
					Name = new char[20];
					cin.ignore();
					cin.getline(Name, 20);
					avto x(num, data, Name);
					L.del(x);
					break;
				}
				case 3: {
					L.Clear();
					break;
				}
				case 4: {
					int y;
					cout << "Enter number:\n";
					cin >> y;
					cout << L[y];
					break;
				}
				case 5: {
					for (int i = 0; i < L.Size; i++) cout << L[i] << '\n';
					cout << '\n';
					break;
				}
				
				
				case 7: {
					MinVisitor<avto, Increase> x;
					L.accept(x);
					break;
				}
				case 8: {
					MaxVisitor<avto, Increase> x;
					L.accept(x);
					break;
				}
				case 9: {
					IMinVisitor<avto, Increase> x;
					L.accept(x);
					break;
				}
				case 10: {
					IMaxVisitor<avto, Increase> x;
					L.accept(x);
					break;
				}

				default: {br = true; }
				}
				if (br) break;
			}
			break;
		}
		}
	}
	catch (const char* x) { cout << x << '\n'; cin.ignore(); cin.get(); return 1; }
}