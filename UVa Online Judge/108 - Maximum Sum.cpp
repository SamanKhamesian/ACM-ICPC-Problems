#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 110

int main()
{
	int n, result = -100000000;

	cin >> n;

	int a[MAX][MAX];

	memset(a, 0, sizeof a);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];

			a[i][j] += a[i][j - 1];
			a[i][j] += a[i - 1][j];

			a[i][j] -= a[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int x = i; x <= n; x++)
			{
				for (int y = j; y <= n; y++)
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

	cout << result << endl;
}