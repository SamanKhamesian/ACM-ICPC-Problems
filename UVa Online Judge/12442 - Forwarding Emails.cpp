#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 50010

int test, t = 1, n;

int result[MAX];
bool visited[MAX];

vector <vector < int > > graph(n);

int dfs(int start)
{
	if (visited[start]) return 0;
	
	visited[start] = true;

	int temp = dfs(graph[start][0]);

	visited[start] = false;

	return result[start] = temp + 1;
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n;

		graph.clear();

		graph.resize(n);

		memset(visited, 0, sizeof visited);

		memset(result, -1, sizeof result);

		for (int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			x--;

			y--;

			graph[x].push_back(y);
		}

		int ans = 999999, tmp = 0;

		for (int i = 0; i < n; i++)
		{
			if (result[i] == -1) dfs(i);

			if (result[i] > tmp)
			{
				tmp = result[i];

				ans = i + 1;
			}

			else if (result[i] == tmp) ans = min(i + 1, ans);
		}

		printf("Case %d: %d\n", t++, ans);
	}
}