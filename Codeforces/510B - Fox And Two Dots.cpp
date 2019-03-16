#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n , m;

string s;

char map[55][55];

bool marked[55][55];

int parent[55][55];

bool dfs(int i , int j)
{
	marked[i][j] = true;

	if (map[i + 1][j] >= 'A' && map[i + 1][j] <= 'Z' && marked[i + 1][j] && (map[i][j] == map[i + 1][j]) && parent[i][j] != ((i) * m) + j)
	{
		return true;
	}

	else if(map[i + 1][j] >= 'A' && map[i + 1][j] <= 'Z' && !marked[i + 1][j] && (map[i][j] == map[i + 1][j]))
	{
		parent[i + 1][j] = ((i - 1) * m) + j;
		
		if (dfs(i + 1, j))
			return true;
	}

	if (map[i - 1][j] >= 'A' && map[i - 1][j] <= 'Z' && marked[i - 1][j] && (map[i][j] == map[i - 1][j]) && parent[i][j] != ((i - 2) * m) + j)
	{
		return true;
	}

	else if (map[i - 1][j] >= 'A' && map[i - 1][j] <= 'Z' && (!marked[i - 1][j]) && (map[i][j] == map[i - 1][j]))
	{
		parent[i - 1][j] = ((i - 1) * m) + j;

		if (dfs(i - 1, j))
			return true;
	}

	if (map[i][j + 1] >= 'A' && map[i][j + 1] <= 'Z' && marked[i][j + 1] && map[i][j] == map[i][j + 1] && parent[i][j] != ((i - 1) * m) + j + 1)
	{
		return true;
	}

	else if (map[i][j + 1] >= 'A' && map[i][j + 1] <= 'Z' && (!marked[i][j + 1]) && (map[i][j] == map[i][j + 1]))
	{
		parent[i][j + 1] = ((i - 1) * m) + j;

		if(dfs(i, j + 1))
			return true;
	}

	if (map[i][j - 1] >= 'A' && map[i][j - 1] <= 'Z' && marked[i][j - 1] && map[i][j] == map[i][j - 1] && parent[i][j] != ((i - 1) * m) + j - 1)
	{
		return true;
	}

	else if (map[i][j - 1] >= 'A' && map[i][j - 1] <= 'Z' && (!marked[i][j - 1]) && (map[i][j] == map[i][j - 1]))
	{
		parent[i][j - 1] = ((i - 1) * m) + j;

		if (dfs(i, j - 1))
			return true;
	}

	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!marked[i][j])
			{
				if (dfs(i, j))
				{
					cout << "Yes";

					exit(0);
				}
			}
		}
	}

	cout << "No";
}