#pragma once
#include <iostream>
#include "Header.h"
//#include "Visitor.h"

using namespace std;

enum { Decay, Increase };

template <class T>
struct node {
	node<T>* next;
	T value;
};

template <class T, int seq>
class Set;

template <class T, int seq>
class Visitor {
public:

	Visitor() {};
	virtual void visit(Set<T, seq>*)=0;
};


template <class T, int seq>
class Set {
private:
	node<T> x;
	node<T> *root;
	node<T> *finish;
	int Compare(T x, T y);
public:
	class iterator
	{
		friend class Set;
	private:
		node<T> * cur_node;
		iterator(node<T>* node) : cur_node(node) {}
	public:
		iterator(iterator* x) : cur_node(x->cur_node) {};
		iterator() : cur_node(nullptr) {}

		iterator operator++() {
			cur_node = cur_node->next;
			return *this;
		}

		bool operator==(iterator y) {
			return (cur_node == y.cur_node);
		}

		bool operator!=(iterator y) {
			return !(cur_node == y.cur_node);
		}

		T operator*() {
			return cur_node->value;
		}
	};
	iterator begin() { return iterator(root); }
	iterator end() { return iterator(finish); }
	int Size = 0;
	Set();
	Set(T* massive, int x);
	Set(Set & x);
	~Set();
	void Clear();
	Set operator =(Set & x);
	T operator [](int x);
	bool put(const T value);
	bool del(const T value);



	void accept(Visitor<T, seq>& v)
	{
		v.visit(this);
	}
};

template <class T, int seq>
Set<T, seq>::Set() {
	root = finish = new node<T>;
}

template <class T, int seq>
Set<T, seq>::Set(T* mas, int x) {
	seq = x;
	root = finish = new node<T>;
	for (auto o : mas) put(o);
}

template <class T, int seq>
int Set<T, seq>::Compare(T x, T y) {
	int ans;
	if (x == y) return 0;
	if (x > y) ans = 1;
	else ans = -1;
	if (seq == Decay) ans = -ans;
	return ans;
}

template <>
int Set<char*, 1>::Compare(char* x, char* y) {
	int ans = strcmp(x, y);
	return ans;
}

template <>
int Set<char*, 0>::Compare(char* x, char* y) {
	int ans = strcmp(x, y);
	return -ans;
}

template <class T, int seq>
Set<T, seq>::~Set() {
	while (root != finish) del(root->value);
}

template <class T, int seq>
void Set<T, seq>::Clear() {
	while (root != finish) del(root->value);
}

template <class T, int seq>
Set<T, seq>::Set(Set & t) {
	t.Clear();
	for (node<T>* i = root; i != finish; i = i->next) t.put(t->value);
	seq = t->seq;
}

template <class T, int seq>
Set<T, seq> Set<T, seq>::operator=(Set & t) {
	t.Clear();
	for (node<T>* i = root; i != finish; i = i->next) t.put(i->value);
	seq = t->seq;
	return this;
}

template <class T, int seq>
T Set<T, seq>::operator[](int x) {
	if (x < 0) throw "Unavailable value";
	node<T>* i = root;
	for (; i != finish && x > 0; x--, i = i->next);
	if (i == finish) throw "Unavailable value";
	return i->value;
}

template <class T, int seq>
bool Set<T, seq>::put(const T x) {
	node<T> *y = new node<T>;
	Size++;
	node<T> *z = root;
	y->next = finish;
	y->value = x;
	if (root != finish)
		for (node<T> * i = root->next; z != finish; i = i->next) {
			if (!Compare(x, z->value)) return "same element exist in a list";
			if (Compare(z->value, x) < 0 && (i == finish || Compare(i->value, x) > 0)) {
				z->next = y;
				y->next = i;
				return true;
			}
			if (i == finish) break; else z = i;
		}
	if (root == finish) root = y;
	else if (Compare(z->value, x) > 0) {
		node<T> *pred = root;
		root = y;
		y->next = pred;
	}
	else z->next = y;
	return true;
}

template <class T, int seq>
bool Set<T, seq>::del(const T x) {
	Size--;
	node<T>*pred = nullptr;
	node<T> *i;
	for (i = root; i != finish && Compare(i->value, x); pred = i, i = i->next);
	if (i == finish) throw "Not found element to delete";
	if (root == i) root = i->next;
	else pred->next = i->next;
	return true;
}



template <class T>
int Comp(T* x, T* y) {
	if (x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

template <char*>
int Comp(char** x, char** y) {
	return strcmp(*x, *y);
}

template <class T, int seq>
class MinVisitor : public Visitor<T, seq> {
public:

	void visit(Set<T, seq>* e) {
		if (e->Size == 0) throw "List is empty!";
		if (seq == 1) cout << (*e)[0] << '\n';
		else cout << (*e)[e->Size - 1] << '\n';
	}
};

template <class T, int seq>
class MaxVisitor : public Visitor<T, seq> {
public:
	void visit(Set<T, seq>* e) {
		if (e->Size == 0) throw "List is empty!";
		if (seq == 0) cout << (*e)[0] << '\n';
		else cout << (*e)[e->Size - 1] << '\n';
	}
};

template <class T, int seq>
class IMinVisitor : public Visitor<T, seq> {
public:
	void visit(Set<T, seq>* e) {
		if (e->Size == 0) throw "List is empty!";
		if (seq == 1) cout << *e->begin() << '\n';
		else {
			auto pi = e->begin();
			for (auto i = e->begin(); i != e->end(); ++i) pi = i;
			cout << *pi << '\n';
		}
	}
};

template <class T, int seq>
class IMaxVisitor : public Visitor<T, seq> {
public:
	void visit(Set<T, seq>* e) {
		if (e->Size == 0) throw "List is empty!";
		if (seq == 0) cout << *e->begin() << '\n';
		else {
			auto pi = e->begin();
			for (auto i = e->begin(); i != e->end(); ++i) pi = i;
			cout << *pi << '\n';
		}
	}
}; 
