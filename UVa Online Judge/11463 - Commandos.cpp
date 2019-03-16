#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 105
#define INF 1E8+7

int town[MAX][MAX];

int main()
{
	int test, t = 1;

	cin >> test;

	while (test--)
	{
		int n, r;

		cin >> n >> r;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				town[i][j] = (i == j) ? 0 : INF;
			}
		}

		for (int i = 0; i < r; i++)
		{
			int x, y;

			cin >> x >> y;

			town[y][x] = town[x][y] = 1;
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					town[i][j] = min(town[i][j], town[i][k] + town[k][j]);
				}
			}
		}

		int startPoint, endPoint;

		cin >> startPoint >> endPoint;

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			if (town[startPoint][i] != INF && town[i][endPoint] != INF)
			{
				ans = max(town[startPoint][i] + town[i][endPoint], ans);
			}
		}

		cout << "Case " << t++ << ": " << ans << endl;
	}
}