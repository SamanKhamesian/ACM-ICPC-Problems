#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

ofstream fout("f.out");

int n;
vector <int> dist, label;
vector <bool> visited;
vector < vector <int > > graph;

bool dfs(int start)
{
	if (start == n) return true;

	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		int child = graph[start][i];

		if (!visited[child] && dfs(child)) return true;
	}

	return false;
}

bool heisenberg()
{
	dist[1] = 100;

	for (int k = 0; k < n - 1; k++)
	{
		for (int head = 1; head <= n; head++)
		{
			for (int i = 0; i < graph[head].size(); i++)
			{
				int child = graph[head][i];

				if (dist[head] > 0 && dist[head] + label[child] > dist[child])
				{
					dist[child] = dist[head] + label[child];
				}
			}
		}
	}

	bool pos = false;

	for (int head = 1; head <= n; head++)
	{
		for (int i = 0; i < graph[head].size(); i++)
		{
			int child = graph[head][i];

			if (dist[head] > 0)
			{
				pos |= (dist[head] + label[child] > dist[child] && dfs(head));
			}
		}
	}

	if (pos || dist[n] > 0) return true;

	else return false;
}

void initialize()
{
	label.clear();
	label.resize(n + 2);

	graph.clear();
	graph.resize(n + 2);

	visited.clear();
	visited.resize(n + 2, false);

	dist.clear();
	dist.resize(n + 2, INT_MIN);
}

int main()
{
	while (cin >> n, n != -1)
	{
		initialize();

		for (int i = 1; i <= n; i++)
		{
			int m, x;

			cin >> label[i];

			cin >> m;

			for (int j = 0; j < m; j++)
			{
				cin >> x;

				graph[i].push_back(x);
			}
		}

		if (heisenberg()) cout << "winnable" << endl;

		else cout << "hopeless" << endl;
	}
}