#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int d = 7;
vector<bool> used(d, true);
vector<vector<int>> vec(d, vector<int>(d));
void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < 6; i++)
		if (vec[v][i])
		{
			vec[v][i] = 0;
			vec[i][v] = 0;
			dfs(i);
		}
}

int main()
{
	
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n = 0, m = 0;//вершины
	in >> n;
	vector<int> amount(d);
	while (!in.eof()) {
		int x, y = 0;
		in >> x >> y;
		vec[x][y] = 1;
		vec[y][x] = 1;
		amount[x]++;
		amount[y]++;

	}
	for (int i = 0; i < amount.size(); i++) {
		if (amount[i] > 0) {
			if (amount[i] % 2 != 0) {
				cout << "No";
				return 0;
			}
			else {
				used[i] = false;
				m = i;
			}
				
		}
	}
	dfs(m);
	for (int i = 0; i < 6; i++) {
		if (!used[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
