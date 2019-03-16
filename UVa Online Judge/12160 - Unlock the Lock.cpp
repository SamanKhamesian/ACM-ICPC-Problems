#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define MAX 10000

int l, u, r, t = 1;

vector <int> dis, buttons;
vector <vector <int> > graph;

int bfs()
{
	dis[l] = 0;

	queue<int> pq;

	pq.push(l);

	while (!pq.empty())
	{
		int head = pq.front();

		pq.pop();

		int childVer;

		for (int i = 0; i < r; i++)
		{
			childVer = graph[head][i];

			if (1 + dis[head] < dis[childVer])
			{
				dis[childVer] = 1 + dis[head];

				pq.push(childVer);
			}
		}
	}

	return dis[u];
}

void initialize(int r)
{
	graph.clear();
	graph.resize(MAX);

	dis.clear();
	dis.resize(MAX, INT_MAX);

	buttons.clear();
	buttons.resize(r);
}

void makeGraph()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < r; j++)
		{
			int child = (i + buttons[j]) % MAX;

			graph[i].push_back(child);
		}
	}
}

int main()
{
	while (cin >> l >> u >> r, l != 0 || u != 0 || r != 0)
	{
		initialize(r);

		for (int i = 0; i < r; i++)
		{
			cin >> buttons[i];
		}

		makeGraph();

		int ans = bfs();

		cout << "Case " << t++ << ": ";

		if (ans != INT_MAX) cout << ans << endl;

		else cout << "Permanently Locked" << endl;
	}
}