#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int grid[510][510];

int main()
{
	int q, n, m;

	cin >> n >> m >> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int k = 0; k < q; k++)
	{
		int x, y;

		cin >> x >> y;

		x--;

		y--;

		grid[x][y] = 1 - grid[x][y];

		int mm = 0;

		for (int i = 0; i < n; i++)
		{
			int first = 0, second = 0;

			for (int j = 0; j < m; j++)
			{
				if (grid[i][j])
				{
					first++;
				}

				else
				{
					first = 0;
				}

				second = max(first, second);
			}

			mm = max(second, mm);
		}

		cout << mm << endl;
	}

	return 0;
}