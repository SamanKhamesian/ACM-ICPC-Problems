#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, k;

long long dp[55][55];

long long  ways(int n, int k)
{
	if (n <= 0 || k == 0)
	{
		return 0;
	}

	if (k == 1 && n <= m)
	{
		return 1;
	}

	if (dp[n][k] != -1)
	{
		return dp[n][k];
	}

	long long ans = 0;

	for (int i = 1; i <= m; i++)
	{
		if (n - i < 0)
		{
			break;
		}

		ans += ways(n - i, k - 1);
	}

	return dp[n][k] = ans;
}

int main()
{
	ios::sync_with_stdio(0);

	while (cin >> n >> k >> m)
	{
		memset(dp, -1, sizeof dp);

		cout << ways(n, k) << endl;
	}
}