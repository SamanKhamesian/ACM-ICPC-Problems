#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 100000

int main()
{
	int t, n, V;

	cin >> t;

	while (t--)
	{
		cin >> V >> n;

		int dp[MAX];

		int coinValue[105];

		memset(coinValue, 0, sizeof coinValue);

		for (int i = 1; i <= n; i++)
		{
			cin >> coinValue[i];
		}

		for (int i = 0; i < MAX; i++)
		{
			dp[i] = MAX;
		}

		dp[0] = 0;

		sort(coinValue + 1, coinValue + n + 1);

		for (int i = 1; i <= n; ++i)
		{
			for (int j = MAX; j >= 0; j--)
			{
				if (j + coinValue[i] <= MAX)
				{
					dp[j + coinValue[i]] = min(dp[j] + 1, dp[j + coinValue[i]]);
				}
			}
		}

		while (dp[V] == MAX)
		{
			V++;
		}

		cout << V << " " << dp[V] << endl;
	}
}