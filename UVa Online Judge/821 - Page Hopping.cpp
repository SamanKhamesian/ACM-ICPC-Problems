#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 105
#define INF 1e7 + 8

int web[MAX][MAX];

void initialize()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			web[i][j] = (i == j) ? 0 : INF;
		}
	}
}

int main()
{
	int x, y, t = 1;

	while (cin >> x >> y, x != 0 || y != 0)
	{
		initialize();

		web[x][y] = 1;

		while (cin >> x >> y, x != 0 || y != 0) web[x][y] = 1;

		for (int k = 0; k < MAX; k++)
		{
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					web[i][j] = min(web[i][j], web[i][k] + web[k][j]);
				}
			}
		}

		int sum = 0;
		double how = 0.0;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (web[i][j] != 0 && web[i][j] != INF)
				{
					how = how + 1.0;

					sum += web[i][j];
				}
			}
		}

		printf("Case %d: average length between pages = %.3f clicks\n", t++, sum / how);
	}
}