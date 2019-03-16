#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 160

int findMax(int a[MAX][MAX], int n)
{
	int result = -100000000;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int x = i; x < n + i && x <= 2 * n; x++)
			{
				for (int y = j; y < n + j && y <= 2 * n; y++)
				{
					int sum = a[x][y];

					sum -= a[x][j - 1];
					sum -= a[i - 1][y];

					sum += a[i - 1][j - 1];

					result = max(result, sum);
				}
			}
		}
	}

	return result;
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		int n;

		cin >> n;

		int a[MAX][MAX];

		memset(a, 0, sizeof a);
	
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> a[i][j];

				a[i][j + n] = a[i + n][j + n] = a[i + n][j] = a[i][j];
			}
		}

		for (int i = 1; i <= n * 2; i++)
		{
			for (int j = 1; j <= n * 2; j++)
			{
				a[i][j] += a[i][j - 1];
				a[i][j] += a[i - 1][j];

				a[i][j] -= a[i - 1][j - 1];
			}
		}

		cout << findMax(a, n) << endl;
	}
}