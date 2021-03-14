#include "K_tree.h"

void K_tree::print()
{
	for (int i = 0; i < Ktrees.size(); i++)
	{
		cout <<Ktrees[i]->getName() << " " << Ktrees[i]->getAge() << " лет ";
			
		switch (Ktrees[i]->getType())
		{
		case 0:cout << "(хвойное) ";
			break;
		case 1:cout << "(лиственное) ";
			break;
		}
		/*cout << " ";
			switch (vec[i]->getClass())
			{
			case 0: cout << "плодовое";
				break;
			case 1: cout << "лесное";

			}*/
		
			cout<< endl;
	}
}

bool compare(Tree * tr1, Tree * tr2)
{
	if (tr1->getName() != tr2->getName())
		return tr1->getName() < tr2->getName();
	else
		return tr1->getAge() > tr2->getAge();
}

void K_tree::printS()
{
	sort(Ktrees.begin(), Ktrees.end(), compare);
	print();
}


int K_tree::countP()
{
	int count = 0;
	for (int i = 0; i < Ktrees.size(); i++)
	{
		if (Ktrees[i]->getType2() == Type2::P)
			count++;
	}
	return count;
}

int K_tree::countL()
{
	int count = 0;
	for (int i = 0; i < Ktrees.size(); i++)
	{
		if (Ktrees[i]->getType2() == Type2::L)
			count++;
	}
	return count;
}

int K_tree::countList()
{
	int count = 0;
	for (int i = 0; i < Ktrees.size(); i++)
	{
		if (Ktrees[i]->getType() == Type1::List)
			count++;
	}
	return count;
}

int K_tree::countHv()
{
	int count = 0;
	for (int i = 0; i < Ktrees.size(); i++)
	{
		if (Ktrees[i]->getType() == Type1::Hv)
			count++;
	}
	return count;
}

void K_tree::add(Tree * tree)
{
	Ktrees.push_back(tree);
}


