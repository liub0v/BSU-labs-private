#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n = 0;//вершины
	int v = 0; 
	int k = 0;
	in >> n;
	vector<bool> used(n);
	vector<vector<int>> vec(n, vector<int>(n));
	vector<vector<int>> vec_tmp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		for (int j = 0; j < n; j++)
		{
			in >> vec[i][j];
		}
	}

	queue<int> que;
	bool flag = 0;
	que.push(v);
	used[v] = true;
	while (!que.empty())
	{
		v = que.front();
		que.pop();
		for (int i = 0; i < n; i++)
			if (vec[v][i] == 1 && used[i] == false)
			{
				vec_tmp[v][i] = 1;
				k++;
				que.push(i);
				used[i] = true;
			}
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == false)
		{
			out << "-1";
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		out << k << endl;
		for (int i = 0; i < vec_tmp.size(); i++)
		{
			for (int j = 0; j < vec_tmp[i].size(); j++)
			{
				if (vec_tmp[i][j] == 1)
					out << i + 1 <<" "<< j + 1 << endl;
			}
		}
	}

	return 0;
}