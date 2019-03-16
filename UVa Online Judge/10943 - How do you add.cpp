#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 105
#define MOD 1000000

int dp[MAX][MAX];

int ways(int n, int k)
{
	if (k == 1)
	{
		return 1;
	}

	if (n == 0)
	{
		return 1;
	}

	if (dp[n][k] != 0)
	{
		return dp[n][k];
	}

	for (int i = 0; i <= n; i++)
	{
		dp[n][k] += ways(n - i, k - 1);

		dp[n][k] = dp[n][k] % MOD;
	}

	return dp[n][k];
}

int main()
{
	int n, k;

	cin >> n >> k;

	while (n != 0 && k != 0)
	{
		memset(dp, 0, sizeof dp);

		cout << ways(n, k) << endl;

		cin >> n >> k;
	}
}