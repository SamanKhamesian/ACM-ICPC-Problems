#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

ofstream fout("f.out");

short grid[105][105];

int test, t = 1, r, c, m, n, w, even = 0, odd = 0;

void dfs(int i, int j)
{
	int temp = 0;

	grid[i][j] = 1;

	map <pair <int, int>, bool> ok;

	if (i + m < r && j + n < c && grid[i + m][j + n] != -1)
	{
		if (grid[i + m][j + n] == 0)
		{
			dfs(i + m, j + n);
		}
		
		if (grid[i + m][j + n] != -1 && ok[make_pair(i + m , j + n)] == 0)
		{
			temp++;

			ok[make_pair(i + m, j + n)] = 1;
		}
	}

	if (i + m < r && j - n >= 0 && grid[i + m][j - n] != -1)
	{
		if (grid[i + m][j - n] == 0)
		{
			dfs(i + m, j - n);
		}

		if (grid[i + m][j - n] != -1 && ok[make_pair(i + m, j - n)] == 0)
		{
			temp++;

			ok[make_pair(i + m, j - n)] = 1;
		}	
	}

	if (i - m >= 0 && j + n < c && grid[i - m][j + n] != -1)
	{
		if (grid[i - m][j + n] == 0)
		{
			dfs(i - m, j + n);
		}

		if (grid[i - m][j + n] != -1 && ok[make_pair(i - m, j + n)] == 0)
		{
			temp++;

			ok[make_pair(i - m, j + n)] = 1;
		}
	}

	if (i - m >= 0 && j - n >= 0 && grid[i - m][j - n] != -1)
	{
		if (grid[i - m][j - n] == 0)
		{
			dfs(i - m, j - n);
		}

		if (grid[i - m][j - n] != -1 && ok[make_pair(i - m, j - n)] == 0)
		{
			temp++;

			ok[make_pair(i - m, j - n)] = 1;
		}
	}

	if (i + n < r && j + m < c && grid[i + n][j + m] != -1)
	{
		if (grid[i + n][j + m] == 0)
		{
			dfs(i + n, j + m);
		}

		if (grid[i + n][j + m] != -1 && ok[make_pair(i + n, j + m)] == 0)
		{
			temp++;

			ok[make_pair(i + n, j + m)] = 1;
		}
	}

	if (i + n < r && j - m >= 0 && grid[i + n][j - m] != -1)
	{
		if (grid[i + n][j - m] == 0)
		{
			dfs(i + n, j - m);
		}

		if (grid[i + n][j - m] != -1 && ok[make_pair(i + n, j - m)] == 0)
		{
			temp++;

			ok[make_pair(i + n, j - m)] = 1;
		}
	}

	if (i - n >= 0 && j + m < c && grid[i - n][j + m] != -1)
	{
		if (grid[i - n][j + m] == 0)
		{
			dfs(i - n, j + m);
		}

		if (grid[i - n][j + m] != -1 && ok[make_pair(i - n, j + m)] == 0)
		{
			temp++;

			ok[make_pair(i - n, j + m)] = 1;
		}
	}

	if (i - n >= 0 && j - m >= 0 && grid[i - n][j - m] != -1)
	{
		if (grid[i - n][j - m] == 0)
		{
			dfs(i - n, j - m);
		}

		if (grid[i - n][j - m] != -1 && ok[make_pair(i - n, j - m)] == 0)
		{
			temp++;

			ok[make_pair(i - n, j - m)] = 1;
		}
	}

	(temp % 2) ? odd++ : even++;

	ok.clear();
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> r >> c >> m >> n;

		memset(grid, 0, sizeof grid);

		cin >> w;

		even = odd = 0;

		for (int i = 0; i < w; i++)
		{
			int x, y;

			cin >> x >> y;

			grid[x][y] = -1;
		}

		dfs(0, 0);

		cout << "Case " << t++ << ":";

		cout << " " << even << " " << odd << endl;
	}
}