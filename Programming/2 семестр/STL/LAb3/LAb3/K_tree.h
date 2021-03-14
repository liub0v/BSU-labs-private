#pragma once
#include <vector>
#include "Ltree.h"
#include "Ptree.h"
#include "Tree.h"
#include <algorithm>
#include <iostream>

using namespace std;

class K_tree
{
public:
	vector<Tree *> Ktrees; 

	K_tree() {};
	~K_tree() {};
	
	int countP();
	int countL();
	int countList();
	int countHv();
	void add(Tree * tree);
	void print();
	void printS();
};

#pragma once
