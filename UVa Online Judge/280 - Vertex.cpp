#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define MAX 200

int n, v, u, how, s;
bool visited[MAX];
vector <vector <int> > graph;

void init()
{
	graph.clear();
	graph.resize(n + 1);
}

int bfs(int source)
{
	for (int i = 0; i < MAX; i++)
	{
		visited[i] = false;
	}

	queue<int> q;

	q.push(source);

	while (!q.empty())
	{
		int x = q.front();

		q.pop();

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];

			if (visited[y] == false)
			{
				q.push(y);

				visited[y] = true;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false) ans++;
	}

	return ans;
}

int main()
{
	while (cin >> n, n != 0)
	{
		init();

		while (cin >> u, u != 0)
		{
			while (cin >> v, v != 0)
			{
				graph[u].push_back(v);
			}
		}

		cin >> how;

		for (int i = 0; i < how; i++)
		{
			int s;

			cin >> s;

			cout << bfs(s);

			for (int i = 1; i <= n; i++)
			{
				if (visited[i] == false) cout << " " << i;
			}

			cout << endl;
		}	
	}
}