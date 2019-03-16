#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 310
#define INF 10000007

struct value
{
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(0);

	int t, s, m;

	cin >> t;

	while (t--)
	{
		cin >> m >> s;

		int dp[MAX][MAX];

		value coinValue[45];

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				dp[i][j] = INF;
			}
		}

		for (int i = 0; i < m; i++)
		{
			int X, Y;

			cin >> X >> Y;

			coinValue[i].x = X;
			coinValue[i].y = Y;
		}

		dp[0][0] = 0;

		for (int i = 0; i < m; i++)
		{
			for (int x = 0; x < MAX; x++)
			{
				for (int y = 0; y < MAX; y++)
				{
					if ((x - coinValue[i].x) >=0 && (y - coinValue[i].y) >= 0)
					{
						dp[x][y] = min(dp[x - coinValue[i].x][y - coinValue[i].y] + 1, dp[x][y]);
					}
				}
			}
		}

		int answer = INF;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (dp[i][j] != INF && ((i*i + j*j) == s*s))
				{
					answer = min(answer, dp[i][j]);
				}
			}
		}

		if (answer == INF)
		{
			cout << "not possible" << endl;
		}

		else
		{
			cout << answer << endl;
		}

	}
}