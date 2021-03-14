#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ifstream in("input.txt");
	int n = 0;//вершины
	int m = 0;//ребра
	int counter = 0;
	in >> n >> m;
	vector<int> vec(n+1);
	int v1, v2;
	while (counter<m)
	{
		in >> v1 >> v2;
		vec[v1]++;
		vec[v2]++;
		counter++;
		
	}

	sort(vec.rbegin(), vec.rend());
	ofstream out;
	out.open("output.txt");
	for ( int i = 0; i < n; i++)
	{
		out << vec[i] << " ";
	}
	
	return 0;
}