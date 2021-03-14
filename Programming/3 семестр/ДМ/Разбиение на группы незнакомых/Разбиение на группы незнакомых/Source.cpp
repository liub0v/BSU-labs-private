#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

bool flag = true;
int k = 1;

void dfs(int, vector<vector<int>>, vector<int>& );

int main()
{
	ifstream in("input.in");
	ofstream out("output.out");
	int n = 0;//вершины
	in >> n;
	vector<int> vec1(n);
	int  temp=0;
	vector<vector<int>> vec(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			in >> temp;
			if (temp == 0 && i != j) {
				vec[i][j]=1;
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		if (vec1[i] == 0)
			dfs(i, vec, vec1);
	}

	if (flag) {
		out<<"YES\n";
		for (int i = 0; i < n; i++) {
			if (vec1[i] == 1) {
				out<<i+1<<" ";
			}
		}
	}
	if (!flag) {
		out<<"NO";
	}

	return 0;
}
void dfs(int i, vector<vector<int>> vec, vector<int> &vec1) {
	vec1[i] = k;
	for (int j = 0; j < vec[i].size(); j++) {
		if (vec[i][j] == 1 && vec1[j] == 0) {
			if (k == 1)
				k = 2;
			else
				k = 1;
			dfs(j, vec, vec1);
		
		}

		else {
			if (vec[i][j] == 1 && vec1[j] != 0) {
				if (vec1[j] == k) {
					flag = false;
					break;
				}
			}

		}
	}
	if (k == 1)
		k = 2;
	else
		k = 1;
}