#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 300

int n, q, m, d, SET, QUERY;

int a[MAX];

int dp[MAX][MAX][30];

int cal(int i, int j, int k)
{
	if (k == m)
	{
		if (j == 0)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	if (i >= n)
	{
		return 0;
	}

	if (dp[i][j][k] != -1)
	{
		return dp[i][j][k];
	}

	return dp[i][j][k] = cal(i + 1, (j + a[i]) % d , k + 1) + cal(i + 1, j % d, k);
}

int main()
{
	cin >> n >> q;

	SET = QUERY = 1;

	while (n != 0 && q != 0)
	{
		memset(a, 0, sizeof a);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cout << "SET " << SET << ":" << endl;

		QUERY = 1;

		while (q--)
		{
			cin >> d >> m;

			memset(dp, -1, sizeof dp);

			int ans = cal(0, 0, 0);

			cout << "QUERY " << QUERY << ": " << ans << endl;

			QUERY++;
		}

		SET++;

		cin >> n >> q;
	}
}