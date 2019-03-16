#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool ok = false;
int test, t = 1, n;
bool visited[105];
char ans[105][105];
bool graph[105][105];

void summarize()
{
	cout << "+";

	for (int i = 0; i < 2 * n - 1; i++) cout << "-";

	cout << "+" << endl;
}

void show()
{
	printf("Case %d:\n", t++);

	for (int i = 0; i < n; i++)
	{
		summarize();

		for (int j = 0; j < n; j++)
		{
			cout << "|";

			if (ans[i][j] == 'Y') cout << 'Y';

			else cout << 'N';
		}

		cout << "|" << endl;
	}

	summarize();
}

void dfs(int source)
{
	visited[source] = true;

	for (int i = 0; i < n; i++)
	{
		if (graph[source][i] && !visited[i])
		{
			dfs(i);
		}
	}
}

void dfsZero(int source)
{
	ans[source][source] = ans[0][source] = 'Y';

	visited[source] = true;

	for (int i = 0; i < n; i++)
	{
		if (graph[source][i] && !visited[i])
		{
			dfsZero(i);
		}
	}
}

int main()
{
	cin >> test;

	while (test--)
	{
		ok = false;

		memset(ans, 0, sizeof ans);
		memset(graph, 0, sizeof graph);
		memset(visited, 0, sizeof visited);

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> graph[i][j];

				ans[i][j] = 'N';
			}
		}

		dfsZero(0);

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				memset(visited, 0, sizeof visited);

				visited[i] = true;

				dfs(0);

				if (!visited[j] && ans[j][j] == 'Y')
				{
					ans[i][j] = 'Y';
				}
			}
		}

		show();
	}
}