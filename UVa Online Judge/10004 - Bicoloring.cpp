#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool ok;
int n, m;
vector <short> colored;
vector < vector <int> > graph;

void bfs(int start)
{
	queue<int> bfsQ;

	bfsQ.push(start);

	colored[start] = 0;

	while (!bfsQ.empty() && ok)
	{
		int top = bfsQ.front();

		bfsQ.pop();

		for (int i = 0; i < graph[top].size(); i++)
		{
			int child = graph[top][i];

			if (colored[child] == colored[top])
			{
				ok = false;
			}

			else if (colored[child] == -1)
			{
				colored[child] = !colored[top];

				bfsQ.push(child);
			}
		}
	}
}

int main()
{
	while (cin >> n, n != 0)
	{
		cin >> m;

		ok = true;

		graph.clear();
		colored.clear();

		graph.resize(n);
		colored.resize(n, -1);

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		bfs(0);

		printf("%s\n", ok ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
}