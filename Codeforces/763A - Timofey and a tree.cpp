#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> color;
vector<bool> visit;
vector< vector<int> > graph;

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		cin >> u >> v;

		graph[u].push_back(v);

		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		int c;

		cin >> c;

		color.push_back(c);
	}
}