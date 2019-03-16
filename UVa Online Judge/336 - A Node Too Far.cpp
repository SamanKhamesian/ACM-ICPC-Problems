#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define INF (int)(1e9)

void initialize(map<int, int> dist)
{
	map<int, int> ::iterator it;

	for (it = dist.begin(); it != dist.end(); it++)
	{
		dist[it->first] = INF;
	}
}

int bfs(int start, int ttl, map < int, vector<int> > graph, map <int, int> dist)
{
	initialize(dist);

	dist[start] = 0;
	
	queue<int> q;

	q.push(start);

	while (!q.empty())
	{
		int u = q.front();

		q.pop();

		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];

			if (dist[v] == INF)
			{
				q.push(v);

				dist[v] = dist[u] + 1;
			}
		}
	}

	int ans = 0;
	map<int, int> ::iterator it;

	for (it = dist.begin(); it != dist.end(); it++)
	{
		if (dist[it->first] > ttl) ans++;
	}

	return ans;
}

int main()
{
	int nc, source, ttl, c = 1;

	while (cin >> nc && nc != 0)
	{
		map <int, int> dist;
		map < int, vector<int> > graph;

		for (int i = 0; i < nc; i++)
		{
			int x, y;

			cin >> x >> y;

			dist[x] = INF;
			dist[y] = INF;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		while (cin >> source >> ttl , (source != 0 || ttl != 0))
		{
			int ans = bfs(source, ttl, graph, dist);

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", c++, ans, source, ttl);
		}
	}
}