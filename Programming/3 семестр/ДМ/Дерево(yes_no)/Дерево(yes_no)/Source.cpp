#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int n, c, Edges;
int arr[101][101], tmp[101];
void dfs(int v)
{
	tmp[v] = 1;
	c++;
	for (int i = 0; i < n; i++)
		if (arr[v][i] && !tmp[i]) 
			dfs(i);
}
void main()
{
	ifstream in("input.txt");
	in >> n;
	Edges = c = 0;
	for(int i=0;i<n;i++){
		for (int j = 0; j < n; j++)
		{
			in >> arr[i][j];
			Edges += arr[i][j];
		}
	}
	memset(tmp, 0, sizeof(tmp));
	dfs(0); 
	Edges /= 2;

	ofstream out;
	out.open("output.txt");
	if ((Edges == n - 1) && (c == n))
		out<<"YES";
	else
		out<<"NO";

}