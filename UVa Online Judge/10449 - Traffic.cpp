#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int n, m, t = 1, q;
#define MAX 100000007

ofstream fout("f.out");

vector <int> label, dist;
vector <vector <int> > graph;

void bellman_ford()
{
	dist[1] = 0;

	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				int child = graph[i][j];

				int weight = label[child] - label[i];

				weight = weight * weight * weight;

				if (dist[i] + weight < dist[child] && dist[i] != MAX)
				{
					dist[child] = weight + dist[i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			int child = graph[i][j];

			int weight = label[child] - label[i];

			weight = weight * weight * weight;

			if (dist[i] + weight < dist[child] && dist[i] != MAX)
			{
				dist[child] = -MAX;
			}
		}
	}
}

void initialize()
{
	label.clear();
	label.resize(n + 3);

	graph.clear();
	graph.resize(n + 3);

	dist.clear();
	dist.resize(n + 3, MAX);
}

int main()
{
	while (cin >> n)
	{
		initialize();

		for (int i = 1; i <= n; i++)
		{
			cin >> label[i];
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			graph[x].push_back(y);
		}

		bellman_ford();

		cin >> q;

		cout << "Set #" << t++ << endl;

		for (int i = 0; i < q; i++)
		{
			int x;

			cin >> x;

			if (dist[x] < 3 || dist[x] == MAX) cout << '?' << endl;

			else cout << dist[x] << endl;
		}
	}
}