#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cstring>
 
using namespace std;

ofstream fout("f.out");

int n, m, test, dfsCount, scc, ans;

stack  <int> points;
vector <bool> visited;
vector <int> dfs_num, dfs_low;
vector < vector <int> > graph;
vector < vector <int> > parent;

void initialize(int n)
{
	ans = 0;
	scc = dfsCount = 0;

	visited.clear();
	visited.resize(n, 0);

	parent.clear();
	parent.resize(n);

	dfs_num.clear();
	dfs_num.resize(n, -1);

	dfs_low.clear();
	dfs_low.resize(n, -1);

	graph.clear();
	graph.resize(n);
}

void dfs(int start)
{
	visited[start] = true;

	points.push(start);

	dfs_num[start] = dfs_low[start] = ++dfsCount;

	for (int i = 0; i < (int)graph[start].size(); i++)
	{
		int child = graph[start][i];

		if (dfs_num[child] == -1) dfs(child);

		if (visited[child]) dfs_low[start] = min(dfs_low[child], dfs_low[start]);
	}

	if (dfs_num[start] == dfs_low[start])
	{
		bool ok = true;

		while (points.top() != start)
		{
			visited[points.top()] = false;

			for (int i = 0; i < parent[points.top()].size(); i++)
			{
				int x = parent[points.top()][i];

				if (dfs_num[x] == -1) ok = false;
			}

			points.pop();
		}

		visited[points.top()] = false;

		for (int i = 0; i < parent[points.top()].size(); i++)
		{
			int x = parent[points.top()][i];

			if (dfs_num[x] == -1) ok = false;
		}

		points.pop();

		if (points.empty() && ok) ans++;
	}
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		initialize(n + 1);

		for (int i = 0; i < m; i++)
		{
			int v, w;

			cin >> v >> w;

			graph[v].push_back(w);

			parent[w].push_back(v);
		}

		for (int i = 1; i <= n; i++)
		{
			if (dfs_num[i] == -1)
			{
				dfs(i);
			}
		}

		cout << ans << endl;
	}
}