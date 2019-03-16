#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

int n, m, s, t;
int test, c = 1;
vector <int> dis;
vector <bool> visited;
vector <vector <pair <int, int> > >  graph;

class comparator
{
public:

	bool operator()(pair<int, int> &child1, pair<int, int> &child2)
	{
		return child1.second > child2.second;
	}
};

priority_queue <pair <int, int>, vector <pair <int, int> >, comparator> pq;

int dijkstra()
{
	visited[s] = true;

	dis[s] = 0;

	pq.push(make_pair(s, dis[s]));

	while (!pq.empty())
	{
		pair <int, int> head = pq.top();

		pq.pop();

		int headVer = head.first;
		int headDis = head.second;

		int childWeight, childVer;

		for (int i = 0; i < (int)graph[headVer].size(); i++)
		{
			childVer = graph[headVer][i].first;

			childWeight = graph[headVer][i].second;

			if (!visited[childVer])
			{
				if (childWeight + headDis < dis[childVer])
				{
					dis[childVer] = childWeight + headDis;

					pq.push(make_pair(childVer, dis[childVer]));
				}
			}
		}
	}

	return dis[t];
}

void initialize(int n)
{
	dis.clear();
	dis.resize(n, INT_MAX);

	graph.clear();
	graph.resize(n);

	visited.clear();
	visited.resize(n, 0);
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m >> s >> t;

		initialize(n);

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}

		int ans = dijkstra();

		cout << "Case #" << c++ << ": ";

		if (ans == INT_MAX) cout << "unreachable" << endl;

		else cout << ans << endl;
	}
}