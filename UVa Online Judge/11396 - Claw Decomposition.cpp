#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
vector <short> color;
vector < vector <int> > graph;

bool bfs(int start)
{
	int b = 0, w = 0;

	queue <int> q;

	q.push(start);

	color[start] = 1;

	while (!q.empty())
	{
		int top = q.front();

		q.pop();

		color[top] ? b++ : w++;

		for (int i = 0; i < graph[top].size(); i++)
		{
			int child = graph[top][i];

			if (color[child] == -1)
			{
				color[child] = !color[top];

				q.push(child);
			}

			else if (color[child] == color[top])
			{
				return false;
			}
		}
	}

	return (abs(b - w)) ? false : true;
}

int main()
{
	while (cin >> n, n != 0)
	{
		bool ans = true;

		graph.clear();
		graph.resize(n);

		color.clear();
		color.resize(n, -1);

		int x, y;

		while (cin >> x >> y, x != 0 || y != 0)
		{
			x--;
			y--;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		if (n % 2 == 1) cout << "NO" << endl;

		else
		{
			for (int i = 0; i < n; i++)
			{
				if (color[i] == -1)
				{
					ans &= bfs(i);
				}
			}

			printf("%s\n", ans ? "YES" : "NO");
		}
	}
}