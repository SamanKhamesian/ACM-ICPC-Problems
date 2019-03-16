#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>

using namespace std;

int n, m, test;
bool hasNegetiveCycle;

ofstream fout("f.out");

vector <int> dist;
vector <vector <pair <int, int> > > graph;

bool bellman_ford()
{
	dist[0] = 0;

	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				int head = i;

				int child = graph[i][j].first;

				int weight = graph[i][j].second;

				dist[child] = min(dist[child], dist[head] + weight);
			}
		}
	}

	hasNegetiveCycle = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			int head = i;

			int child = graph[i][j].first;

			int weight = graph[i][j].second;

			if (dist[head] + weight < dist[child])
			{
				hasNegetiveCycle = true;
			}
		}
	}

	return hasNegetiveCycle;
}

void initialize()
{
	hasNegetiveCycle = false;

	graph.clear();
	graph.resize(n);

	dist.clear();
	dist.resize(n, INT_MAX);
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		initialize();

		for (int i = 0; i < m; i++)
		{
			int x, y, t;

			cin >> x >> y >> t;

			graph[x].push_back(make_pair(y, t));
		}

		if (bellman_ford()) cout << "possible" << endl;
	
		else cout << "not possible" << endl;
	}
}