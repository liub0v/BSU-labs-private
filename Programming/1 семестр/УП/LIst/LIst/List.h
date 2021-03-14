#pragma once
#include <iostream>
#include<string>
using namespace std;
 
template <class Data> class List
{
	class Node
	{
	public:
		Data d;
		Node *next, *prev;
		Node(Data det = 0) { d = det; next = 0; prev = 0; }
		Node() {};
		~Node() {};
	};
public:
	
	Node *pbeg, *pend;
	List() { pbeg = 0; pend=0; }
	~List();
	void add(Data d);
	Node * find(Data d)
	{
		Node *pv = pbeg;
		while (pv)
		{
			if (pv->d == d)
				break;
			throw("Not Found\n");
			pv = pv->next;
			return 0;
		}
		return pv;
	};
	Node * insert(Data key, Data d)
	{
		if (Node *key - find(key))
		{
			Node *pv = new Node(d);
			pv->next = key->next;
			pv->prev = key;
			key->next = pv;
			if (key != pend)
				(pv->next)->prev = pv;
			else pend = pv;
			return pv;
		}
		return 0;
	}
	bool remove(Data key);
	void print();
	void print_back();
};

template<class Data>
inline List<Data>::~List()
{
	if (pbeg != 0)
	{
		Node *pv = pbeg;
		while (pv)
		{
			pv = pv->next;
			delete pbeg;
			pbeg = pv;
		}

	}
}

template<class Data>
inline void List<Data>::add(Data d)
{
	Node *pv = new Node(d);
	if (pbeg == 0)
		pbeg = pend = pv;
	else
	{
		pv->prev = pend;
		pend->next = pv;
		pend = pv;
	}
}


template<class Data>
inline bool List<Data>::remove(Data key)
{
	if (Node *key = find(key))
	{
		if (key == pbeg)
		{
			pbeg=pbeg->next;
			pbeg->prev=0;
		}
		else if (key == pend)
		{
			pend=pend->prev;
			pend->next=0;
		}
		else
		{
			(key->prev)->next = key->next;
			(key->next)->prev = key->prev;
		}
		delete key;
		return true;
	}
	return false;
}

template<class Data>
inline void List<Data>::print()
{
	Node *pv = pbeg;
	cout << endl << "List: ";
	while (pv)
	{
		cout << pv->d << ' ';
		pv = pv->next;
	}
	cout << endl;
}

template<class Data>
inline void List<Data>::print_back()
{
	Node *pv = pend;
	cout << endl << "List back: ";
	while (pv)
	{
		cout << pv->d << ' ';
		pv = pv->prev;
	}
	cout << endl;
}
