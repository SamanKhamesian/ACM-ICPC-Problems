#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

#define MAX 10005
int test, n, m, s, t, p, ans;

ofstream fout("f.out");

int dist[2][MAX];
vector <vector <vector <pair <int, int> > > >graph;
vector <pair < pair <int, int>, int> > edges;

void dijkstar(int pos, int start)
{
	dist[pos][start] = 0;

	queue<int> pq;

	pq.push(start);

	while (!pq.empty())
	{
		int head = pq.front();

		pq.pop();

		for (int i = 0; i < graph[pos][head].size(); i++)
		{
			int child = graph[pos][head][i].first;

			int weight = graph[pos][head][i].second;

			if (dist[pos][child] > weight + dist[pos][head])
			{
				dist[pos][child] = weight + dist[pos][head];

				pq.push(child);
			}
		}
	}
}

void initialize()
{
	ans = -1;

	graph.clear();
	graph.resize(2);

	graph[0].resize(n + 1);
	graph[1].resize(n + 1);

	edges.clear();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			dist[i][j] = 100000000;
		}
	}
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m >> s >> t >> p;

		initialize();

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			edges.push_back(make_pair(make_pair(x, y), w));

			graph[0][x].push_back(make_pair(y, w));
			graph[1][y].push_back(make_pair(x, w));
		}

		dijkstar(0, s);
		dijkstar(1, t);

		for (int i = 0; i < edges.size(); i++)
		{
			pair < pair <int, int>, int > head = edges[i];

			int x, y, w;

			x = head.first.first;
			y = head.first.second;
			w = head.second;

			if (dist[0][x] + w + dist[1][y] <= p) ans = max(ans, w);
		}

		cout << ans << endl;
	}
}