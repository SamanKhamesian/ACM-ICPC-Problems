#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

ofstream fout("f.out");

int n, m, dfsCount, ans;

stack <int> points;
vector <bool> visited;
vector < vector <int> > town;
vector <int> dfs_num, dfs_low;

void initialize(int n)
{
	ans = dfsCount = 0;

	visited.clear();
	visited.resize(n, 0);

	town.clear();
	town.resize(n);

	dfs_num.clear();
	dfs_num.resize(n, -1);

	dfs_low.clear();
	dfs_low.resize(n, -1);
}

void dfs(int start)
{
	points.push(start);

	visited[start] = true;

	dfs_num[start] = dfs_low[start] = ++dfsCount;

	for (int i = 0; i < (int)town[start].size(); i++)
	{
		int child = town[start][i];

		if (dfs_num[child] == -1) dfs(child);

		if (visited[child]) dfs_low[start] = min(dfs_low[start], dfs_low[child]);
	}

	if (dfs_low[start] == dfs_num[start])
	{
		ans++;

		while (points.top() != start)
		{
			visited[points.top()] = false;

			points.pop();
		}

		visited[points.top()] = false;

		points.pop();
	}
}

int main()
{
	while (cin >> n >> m, n != 0 || m != 0)
	{
		initialize(n);

		for (int i = 0; i < m; i++)
		{
			int v, w, p;

			cin >> v >> w >> p;

			v--;
			w--;

			town[v].push_back(w);

			if (p == 2) town[w].push_back(v);
		}

		for (int i = 0; i < n; i++) if (dfs_num[i] == -1) dfs(i);

		if (ans == 1) cout << 1 << endl;

		else cout << 0 << endl;
	}
}