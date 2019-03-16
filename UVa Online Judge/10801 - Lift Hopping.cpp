#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, k;
map <int, int> label;
vector <vector <int> > floors;
vector <int> times, dis;
vector <vector <pair <int, int> > > graph;

ofstream fout("f.out");

int dijkstra()
{
	queue <int> q;

	dis[0] = 0;

	q.push(0);

	while (!q.empty())
	{
		int head = q.front();

		q.pop();

		for (int i = 0; i < graph[head].size(); i++)
		{
			int childVer = graph[head][i].first;

			int weight = graph[head][i].second;

			int totalWeight = (int)(abs(head - childVer) * weight);

			if (totalWeight + dis[head] + 60 < dis[childVer])
			{
				dis[childVer] = dis[head] + totalWeight + 60;

				q.push(childVer);
			}
		}
	}

	return dis[k];
}

void initialize()
{
	label.clear();

	times.clear();
	times.resize(n);

	floors.clear();
	floors.resize(n);

	graph.clear();
	graph.resize(100);

	dis.clear();
	dis.resize(100, INT_MAX);
}

int main()
{
	while (cin >> n >> k)
	{
		initialize();

		for (int i = 0; i < n; i++)
		{
			cin >> times[i];
		}

		cin.ignore();

		for (int i = 0; i < n; i++)
		{
			int t;

			string s;

			getline(cin, s);

			stringstream ss(s);

			while (ss >> t)
			{
				floors[i].push_back(t);

				label[t] = i;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < floors[i].size(); j++)
			{
				for (int k = j + 1; k < floors[i].size(); k++)
				{
					int x = floors[i][j];
					int y = floors[i][k];
					int w = times[i];

					graph[x].push_back(make_pair(y, w));
					graph[y].push_back(make_pair(x, w));
				}
			}
		}

		int ans = dijkstra();

		if (ans == INT_MAX) cout << "IMPOSSIBLE" << endl;

		else if (ans < 60) cout << ans << endl;

		else cout << ans - 60 << endl;
	}
}