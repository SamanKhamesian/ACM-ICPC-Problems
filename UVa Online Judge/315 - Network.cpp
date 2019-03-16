#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string s;
int u, v, n, root, ans, rootChildern = 0, dfsCount = 0;

vector <bool> visited;
vector <int> parent;
vector <int> cutVertex;
vector < vector <int> > graph;
vector <int> entryTime, bestTime;

void find(int start)
{
	visited[start] = true;

	entryTime[start] = bestTime[start] = dfsCount++;

	for (int i = 0; i < (int)graph[start].size(); i++)
	{
		int child = graph[start][i];

		if (!visited[child])
		{
			parent[child] = start;

			if (start == root) rootChildern++;

			find(child);

			// if we want cut-edge -> use ">" and (start, child) is a edge.
			if (bestTime[child] >= entryTime[start])
			{
				cutVertex[start] = true;
			}

			bestTime[start] = min(bestTime[start], bestTime[child]);
		}

		else if (child != parent[start])
		{
			bestTime[start] = min(bestTime[start], entryTime[child]);
		}
	}
}

int main()
{
	while (true)
	{
		cin >> n;

		if (n == 0) break;

		getline(cin, s);

		dfsCount = ans = 0;

		graph.clear();
		graph.resize(n);

		parent.clear();
		parent.resize(n, -1);

		cutVertex.clear();
		cutVertex.resize(n, 0);

		entryTime.clear();
		entryTime.resize(n, 0);

		visited.clear();
		visited.resize(n, 0);

		bestTime.clear();
		bestTime.resize(n, 0);

		while (true)
		{
			getline(cin, s);

			istringstream is(s);

			is >> u;

			if (u == 0) break;

			u--;

			while (is >> v)
			{
				v--;

				graph[v].push_back(u);
				graph[u].push_back(v);
			}
		}

		root = 0;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				root = i;

				rootChildern = 0;

				find(i);
			}

			cutVertex[root] = (rootChildern > 1) ? true : false;
		}

		for (int i = 0; i < n; i++)
		{
			ans += cutVertex[i];
		}

		cout << ans << endl;
	}
}