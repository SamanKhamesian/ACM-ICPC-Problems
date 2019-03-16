#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 100

int n, l;
int dp[MAX][MAX];

int minCost(vector<int> a, int left, int right)
{

	if (right - left == 1)
	{
		return 0;
	}

	if (dp[left][right] != -1)
	{
		return dp[left][right];
	}

	int ans = 999999999;

	for (int i = left + 1; i < right; i++)
	{
		ans = min(ans, minCost(a, left, i) + minCost(a, i, right) + (a[right] - a[left]));
	}

	return dp[left][right] = ans;
}

int main()
{
	cin >> l;

	while (l != 0)
	{
		cin >> n;

		vector<int> points;

		memset(dp, -1, sizeof dp);

		points.push_back(0);

		for (int i = 0; i < n; i++)
		{
			int x;

			cin >> x;

			points.push_back(x);
		}

		points.push_back(l);

		int ans = minCost(points, 0, n + 1);

		printf("The minimum cutting is %d.\n", ans);

		cin >> l;
	}
}