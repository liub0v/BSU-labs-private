//Îáğàòíàÿ ïîëüñêàÿ çàïèñü
/*
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;
string rec[200];
int n=0;
// ÏÅĞÅÂÎÄ ÈÇ ÈÍÔÈÊÑÍÎÉ Â ÏÎÑÒÔÈÊÑÍÓŞ ÔÎĞÌÓ
bool TryParse(const string &symbol);// ÏĞÎÒÎÒÈÏÛ ÔÓÍÊÖÈÉ
int Priority(const string &c);
bool isOperator(const string &c);
int postfix(string infix);

int postfix(string infix)
{
	istringstream iss(infix);
	vector<string> tokens;//ÕĞÀÍÅÍÈÅ ÑÈÌÂÎËÎÂ
	while(iss)
	{
		string temp;
		iss >>temp;
		tokens.push_back(temp);
		//cout<< temp<< " ";

	}
	vector<string> outputList;//ÈÒÎÃÎÂÛÉ ÂÅÊÒÎĞ
	stack<string> s;//ÎÑÍÎÂÍÎÉ ÑÒİÊ
	for(unsigned int i = 0; i < tokens.size(); i++)  //×ÒÅÍÈÅ
	{
	   if (TryParse(tokens[i]))
		{
			outputList.push_back(tokens[i]);
		}

		if(tokens[i] == "(")
		{
			s.push(tokens[i]);
		}
		if(tokens[i] == ")")
		{
			while(!s.empty() && s.top() != "(")
			{
				outputList.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		if(isOperator(tokens[i]) == true)
		{
			while(!s.empty() && Priority(s.top()) >= Priority(tokens[i]))
			{
				outputList.push_back(s.top());
				s.pop();
			}
			s.push(tokens[i]);
		}
	}
	//ÂÑÅ ÎÑÒÀÂØÈÅÑß İËÅÌÅÍÒÛ ÑÒİÊÀ Â ÈÒÎÃÎÂÛÉ ÂÅÊÒÎĞ
	while(!s.empty()) {
		outputList.push_back(s.top());
		s.pop();
	}

	for (int i=0; i< outputList.size(); i++)
	{
		rec[i]=outputList[i];
		cout << rec[i]<< " ";
		++n;

	}
	cout<<endl;
	return 0;
}
bool TryParse(const string &symbol)
{
	bool isNumber = false;
	for(unsigned int i = 0; i < symbol.size(); i++)
	{
		if (isdigit(symbol[i]))
		{
			isNumber = true;
		}
	}
	return isNumber;
}
int Priority(const string &c)
{

	if(c == "*" || c == "/")
	{
		return 2;
	}
	if(c== "+" || c == "-")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool isOperator(const string &c)
{
	return (c == "+" || c == "-" || c == "*" || c == "/");
}

//ÂÛ×ÈÑËÅÍÈÅ ÂÛĞÀÆÅÍÈß
struct Data {
	double d;
};

struct Node {
	Data data;
	Node * prev;
};

struct Stack {
	Node * end;
	size_t size;
};

inline void CopyData(Data & dst, const Data & src)
{
	dst.d = src.d;
}

void Init(Stack & stk, const Data * data)
{
	Node * newItem = new Node;
	CopyData(newItem->data, *data);
	stk.end = newItem;
	stk.end->prev = 0;
	stk.size = 1;
}

void Clear(Stack & stk)
{
	if (stk.size == 0)
		return;

	for (int i = 0; i < stk.size; ++i)
	{
		Node * oldItem = stk.end;
		stk.end = stk.end->prev;
		delete oldItem;
	}
	stk.end = 0;
	stk.size = 0;
}

void Push(Stack & stk, const Data & data)
{
	if (stk.size == 0) {
		Init(stk, &data);
		return;
	}
	Node * newItem = new Node;
	CopyData(newItem->data, data);
	newItem->prev = stk.end;
	stk.end = newItem;
	++stk.size;
}

Data Pop(Stack & stk)
{
	if (stk.size == 1)
	{
		Data m = stk.end->data;
		delete stk.end;
		stk.end = 0;
		stk.size = 0;
		return m;
	}
	Node * oldItem = stk.end;
	stk.end = stk.end->prev;
	Data m = oldItem->data;
	delete oldItem;
	--stk.size;
	return m;
}

void Operation(string sign, Stack & stk)
{
	if (sign == "+")
	{
		Data m;
		double a, b;
		b = Pop(stk).d;
		a = Pop(stk).d;
		m.d = a + b;
		Push(stk, m);
		return;
	}
	if (sign == "-")
	{
		Data m;
		double a, b;
		b = Pop(stk).d;
		a = Pop(stk).d;
		m.d = a - b;
		Push(stk, m);
		return;
	}
	if (sign == "*")
	{
		Data m;
		double a, b;
		b = Pop(stk).d;
		a = Pop(stk).d;
		m.d = a * b;
		Push(stk, m);
		return;
	}
	if (sign == "/")
	{
		Data m;
		double a, b;
		b = Pop(stk).d;
		a = Pop(stk).d;
		m.d = a / b;
		Push(stk, m);
		return;
	}
	else
	{
		Data n;
		n.d =(double) stoi (sign);
		Push(stk, n);
		return;
	}
}

//ÃËÀÂÍÀß ÔÓÍÊÖÈß
int main()
{
	string infix;
	ifstream fin("ÎÏÇ_Âûğàæåíèå.txt"); //×ÒÅÍÈÅ ÈÇ ÔÀÉËÀ
	getline(fin, infix);
	postfix(infix);
	Stack stk;
	stk.size = 0;
	for (int i = 0; i<n; ++i)
	{
	   Operation(rec[i], stk);
	}
	ofstream fout("ÎÏÇ_Ğåçóëüòàò.txt"); //ÇÀÏÈÑÜ Â ÔÀÉË
	fout << stk.end->data.d << ' ';
	cout << stk.end->data.d << ' ';
	Clear(stk);
	return 0;
}
*/