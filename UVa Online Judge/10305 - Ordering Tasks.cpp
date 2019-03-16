#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int n, m;
stack <int> topo;
vector <bool> visited;
vector < vector <int> > graph;

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < (int)graph[start].size(); i++)
	{
		int child = graph[start][i];

		if (!visited[child])
		{
			dfs(child);
		}
	}

	topo.push(start + 1);
}

int main()
{
	while (cin >> n >> m , n != 0 || m != 0)
	{
		graph.clear();

		visited.clear();

		graph.resize(n);

		visited.resize(n, 0);

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			x--;

			y--;

			graph[x].push_back(y);
		}

		for (int i = 0; i < n; i++)
		{
			if (!visited[i]) dfs(i);
		}

		while (!topo.empty())
		{
			cout << topo.top() << " ";

			topo.pop();
		}

		cout << endl;
	}
}