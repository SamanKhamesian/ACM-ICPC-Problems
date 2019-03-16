#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int n, m, t, e, ans = 0, lim;

ofstream fout("f.out");

vector <int> dis;
vector <vector <pair <int, int> > > graph;

class comparator
{
public:

	bool operator()(pair <int, int> &child1, pair <int, int> &child2)
	{
		return child1.second > child2.second;
	}
};

void dijkstra()
{
	priority_queue <pair <int, int>, vector <pair <int, int> >, comparator>pq;

	dis[e] = 0;

	pq.push(make_pair(e, dis[e]));

	while (!pq.empty())
	{
		pair <int, int> head = pq.top();

		pq.pop();

		int headVer = head.first;
		int headDis = head.second;

		int childVer, childWeight;

		for (int i = 0; i < (int)graph[headVer].size(); i++)
		{
			childVer = graph[headVer][i].first;

			childWeight = graph[headVer][i].second;

			if (headDis + childWeight < dis[childVer])
			{
				dis[childVer] = headDis + childWeight;

				pq.push(make_pair(childVer, dis[childVer]));
			}
		}
	}
}

void initialize(int n)
{
	ans = 0;

	graph.clear();
	graph.resize(n + 1);

	dis.clear();
	dis.resize(n + 1, INT_MAX);
}

int main()
{
	bool first = true;

	cin >> t;

	while (t--)
	{
		cin >> n >> e >> lim >> m;

		initialize(n);

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			graph[y].push_back(make_pair(x, w));
		}

		dijkstra();

		for (int i = 1; i <= n; i++)
		{
			if (dis[i] <= lim) ans++;
		}

		if (!first) cout << endl;

		else first = false;

		cout << ans << endl;
	}
}