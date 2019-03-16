#include <iostream>
#include <cstring>
#include <Vector>
#include <algorithm>

using namespace std;

#define MIN -1000000007

bool dp[2][210];
int m, c, k, price[25][25];

int main()
{
	int t, result = 0;

	cin >> t;

	while (t--)
	{
		cin >> m >> c;

		memset(price, 0, sizeof price);

		for (int i = 0; i < c; i++)
		{
			cin >> price[i][0];

			for (int j = 1; j <= price[i][0]; j++)
			{
				cin >> price[i][j];
			}
		}

		memset(dp, false, sizeof dp);

		for (int i = 1; i <= price[0][0]; i++)
		{
			if (m - price[0][i] >= 0)
			{
				dp[1][m - price[0][i]] = true;
			}
		}

		for (int i = 1; i < c; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				dp[0][j] = dp[1][j];
				dp[1][j] = false;
			}

			for (int j = 0; j <= m; j++)
			{
				if (dp[0][j])
				{
					for (int k = 1; k <= price[i][0]; k++)
					{
						if (j - price[i][k] >= 0)
						{
							dp[1][j - price[i][k]] = true;
						}
					}
				}
			}
		}
	
		for (result = 0; result <= m && !dp[1][result]; result++);

		if (result == m + 1)
		{
			cout << "no solution" << endl;
		}
	}
}
