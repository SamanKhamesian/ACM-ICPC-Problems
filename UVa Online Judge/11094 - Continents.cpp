#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

ofstream fout("f.out");

char gold;
int m, n, x, y;
int maximum = 0, dfsCount = 0;

int comp[25][25];
vector <string> world;

void dfs(int i, int j, int& temp)
{
	temp++;

	comp[i][j] = dfsCount;

	if (i - 1 >= 0 && world[i - 1][j] == gold && comp[i - 1][j] == -1)
	{
		dfs(i - 1, j, temp);
	}

	if (i + 1 < m && world[i + 1][j] == gold && comp[i + 1][j] == -1)
	{
		dfs(i + 1, j, temp);
	}

	if (world[i][(j + 1 + n) % n] == gold && comp[i][(j + 1 + n) % n] == -1)
	{
		dfs(i, (j + 1 + n) % n, temp);
	}

	if (world[i][(j - 1 + n) % n] == gold && comp[i][(j - 1 + n) % n] == -1)
	{
		dfs(i, (j - 1 + n) % n, temp);
	}
}

int main()
{
	while (cin >> m >> n)
	{
		maximum = dfsCount = 0;

		world.clear();

		memset(comp, -1, sizeof comp);

		for (int i = 0; i < m; i++)
		{
			string s;

			cin >> s;

			world.push_back(s);
		}

		cin >> x >> y;

		gold = world[x][y];

		int temp = 0;

		dfs(x, y, temp);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp = 0;

				if (world[i][j] == gold && comp[i][j] == -1)
				{
					dfs(i, j, temp);

					maximum = max(temp, maximum);

					dfsCount++;
				}
			}
		}

		cout << maximum << endl;
	}
}