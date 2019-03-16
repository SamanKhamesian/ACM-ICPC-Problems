#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 120

int main()
{
	ios::sync_with_stdio(false);

	int t, n, m, k, counter = 1;

	cin >> t;

	while (t--)
	{
		long long area = 0, result = 0;

		cin >> n >> m >> k;

		long long a[MAX][MAX];

		memset(a, 0, sizeof a);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];

				a[i][j] += a[i][j - 1];
				a[i][j] += a[i - 1][j];

				a[i][j] -= a[i - 1][j - 1];
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int x = i; x <= n; x++)
				{
					for (int y = j; y <= m; y++)
					{
						long long tmp = 0;
						long long sum = a[x][y];

						sum -= a[x][j - 1];
						sum -= a[i - 1][y];

						sum += a[i - 1][j - 1];

						tmp = (x - i + 1) * (y - j + 1);

						if (sum <= k)
						{
							if (tmp == area)
							{
								result = min(result, sum);
							}

							else if (tmp > area)
							{
								result = sum;
								area = tmp;
							}
						}
					}
				}
			}
		}

		cout << "Case #" << counter << ": " << area << " " << result << endl;
		counter++;
	}
}