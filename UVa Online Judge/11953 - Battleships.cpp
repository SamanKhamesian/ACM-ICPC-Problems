#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int test, t = 1, n, ans = 0;

vector <string> grid;

int directionX[4] = { 1, 0, -1, 0 };
int directionY[4] = { 0, 1, 0, -1 };

bool ok(int i, int j, int num)
{
	if (i + directionX[num] < n && i + directionX[num] >= 0 && j + directionY[num] < n && j + directionY[num] >= 0) return true;

	else return false;
}

void dfs(int i, int j)
{
	grid[i][j] = '.';

	for (int k = 0; k < 4; k++)
	{
		if (ok(i, j, k) && grid[i + directionX[k]][j + directionY[k]] != '.')
		{
			dfs(i + directionX[k], j + directionY[k]);
		}
	}
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n;

		grid.clear();

		ans = 0;

		for (int i = 0; i < n; i++)
		{
			string s;

			cin >> s;

			grid.push_back(s);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 'x')
				{
					ans++;

					dfs(i, j);
				}
			}
		}

		cout << "Case " << t++ << ": " << ans << endl;
	}
}