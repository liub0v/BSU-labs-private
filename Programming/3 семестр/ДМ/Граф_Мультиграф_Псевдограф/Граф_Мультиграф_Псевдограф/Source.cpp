#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int x, y = 0;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n = 0;//вершины
	int m = 0;//ребра
	bool isGraf = true;
	bool isPseud = true;
	bool isMulti = true;
	in >> n >> m;
	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		in >> x >> y;
		if (x-1 == y-1) {
			isGraf = false; isMulti = false; break;
		}
		else
			if (vec[x-1][y-1] == 1 || vec[y-1][x-1] == 1)
				isGraf = false;
		vec[x-1][y-1] = 1;
		vec[y-1][x-1] = 1;
	}
	out << (isGraf ? "Yes\n" : "No\n");
	out << (isMulti ? "Yes\n" : "No\n");
	out << (isPseud ? "Yes\n" : "No\n");

	return 0;


}