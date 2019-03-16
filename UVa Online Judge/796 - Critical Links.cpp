#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

int n, dfsCount = 0;

vector <bool> visited;
set < pair <int, int> > ans;
vector <vector <int>> graph;
vector <int> num, low, parent;

void find(int source)
{
	visited[source] = true;

	num[source] = low[source] = dfsCount++;

	for (int i = 0; i < (int)graph[source].size(); i++)
	{
		int child = graph[source][i];

		if (!visited[child])
		{
			parent[child] = source;

			find(child);

			low[source] = min(low[source], low[child]);

			if (low[child] > num[source])
			{
				ans.insert(make_pair(min(source, child), max(source, child)));
			}
		}

		else if (child != parent[source])
		{
			low[source] = min(low[source], num[child]);
		}
	}
}

int main()
{
	while (cin >> n)
	{
		dfsCount = 0;

		ans.clear();

		graph.clear();
		graph.resize(n);

		visited.clear();
		visited.resize(n, 0);

		num.clear();
		num.resize(n, 0);

		low.clear();
		low.resize(n, 0);

		parent.clear();
		parent.resize(n, -1);

		for (int i = 0; i < n; i++)
		{
			int x, s, y;
			char c;

			cin >> x >> c >> s >> c;

			for (int i = 0; i < s; i++)
			{
				cin >> y;

				graph[x].push_back(y);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				find(i);
			}
		}

		cout << ans.size() << " critical links" << endl;

		set < pair <int, int>> :: iterator i;

		for (i = ans.begin(); i != ans.end() ; i++)
		{
			pair <int, int> answer = *i;

			cout << answer.first << " - " << answer.second << endl;
		}

		cout << endl;
	}
}