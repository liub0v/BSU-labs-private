#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	ifstream in("input.in");
	ofstream out("output.out");
	int n = 0;//вершины
	int v = 0;
	int k = 1;
	in >> n;
	vector<bool> used(n);
	vector<vector<int>> vec(n, vector<int>(n));
	vector<vector<int>> vec_tmp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			in >> vec[i][j];
		}
	}
	queue<int> que;
	que.push(v);
	used[v] = true;
	while ((que.empty() == false) && (k != n))
	{
		v = que.front();
		for (int i = 0; i < n; i++)
		{
			if ((vec[v][i] == 1) && (used[i] == false))
			{
				que.push(i);
				used[i] = true;
				k++;
			}
		}
		que.pop();
	}
	if (k == n)
	{
		out<<"YES";
	}
	else
	{
		out<<"NO";
	}
	return 0;
}