#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 30002

long long dp[MAX];
long long coins[5] = { 1, 5, 10, 25, 50 };

int main()
{
	ios::sync_with_stdio(false);

	long long n;

	while (cin >> n)
	{
		memset(dp, 0, sizeof dp);

		dp[0] = 1;

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (j - coins[i] >= 0)
				{
					dp[j] += dp[j - coins[i]];
				}
			}
		}

		long long answer = dp[n];

		if (answer == 1 || answer == 0)
		{
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}

		else
		{
			cout << "There are " << answer << " ways to produce " << n << " cents change." << endl;
		}
	}
}