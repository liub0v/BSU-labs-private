#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iomanip>
#include <cstring>
using namespace std;

const char* filename = "dbase";
enum Action {INSERT,DEL,INFO};
enum Dir {LEFT,RIGHT};
const int l_time = 20, l_type = 40, l_number = 12;

struct Fine // оплата за разговор
{
	char time[l_time]; // время разговора
	char type[l_type]; // тип разговора
	float price; // тариф
	Fine* next; // указатель на следующий элемент
};
struct Node
{
	char number[l_number];
	Fine* beg;
	Node* left; 
	Node* right;

};
struct Data// исходные данные
{
	char numder[l_number];
	char time[l_time];
	char type[l_type];
	float price;
};
Node* descent(Node* p);
Node* first(Data data);
Data input(Action action);
int menu();
void print_node(const Node& node);
void print_dbase(Node* p);
Node* read_dbase( const char* filename);
int read_fine(ifstream f, Data& data);
int remove_fine(Node* p, const Data& data);
void remove_fines(Node* p);
Node* remove_node(Node* root, Node* p, Node* parent, Dir dir);
Node* remove_tree(Node* p);
Node* search_insert(Node* root, const Data& data, Action action, Dir& dir, Node*& parent); 
void write_dbase(ofstream f, const Node* root);
void write_node(ofstream f, const Node& node);
int main()
{
	Node* p, *parent;
	Node* root = read_dbase(filename);
	ofstream fout;
	Dir dir;
	while (true)
	{
		switch (menu())
		{
		case 1:
			if (!root) root = first(input(INSERT));
			else search_insert(root, input(INSERT), INSERT, dir, parent);
			break;
		case 2:
			if (!root)
			{
				cout << "Base is empty" << endl;
				break;
			}
			Data data = input(DEL);
			if (!(p = search_insert(root, data, DEL, dir, parent)))
				cout << "No information " << endl;
			else
				if (remove_fine(p, data) == 2)
					root = remove_node(root, p, parent, dir);
			break;
		case 3:
			if (!root)
			{
				cout << "Base is empty" << endl; break;
			}
			if (!(p = search_insert(root, input(INFO), INFO, dir, parent)))
				cout << "No information " << endl;
			else print_node(*p);
			break;
		case 4:
			fout.open(filename);
			if (!fout.is_open())
			{
				cout << "Error" << filename << endl; return 1;
			}
			write_dbase(fout, root);
			return 0;
		case 5:
			print_dbase(root);
			break;
		default:
			cout << "Enter the numder from 1 to 4" << endl;
			break;
		}
	}
	return 0;
}