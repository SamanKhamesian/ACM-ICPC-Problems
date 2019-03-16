#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

#define MAX 25

int main()
{
	ios::sync_with_stdio(0);

	long long a, b, c, t, result;

	cin >> t;

	while (t--)
	{
		cin >> a >> b >> c;

		long long map[MAX][MAX][MAX];

		result = -1000000000000000;

		memset(map, 0, sizeof map);

		for (long long i = 1; i <= a; i++)
		{
			for (long long j = 1; j <= b; j++)
			{
				for (long long k = 1; k <= c; k++)
				{
					cin >> map[i][j][k];

					map[i][j][k] += map[i][j][k - 1];
					map[i][j][k] += map[i][j - 1][k];
					map[i][j][k] += map[i - 1][j][k];

					map[i][j][k] -= map[i][j - 1][k - 1];
					map[i][j][k] -= map[i - 1][j - 1][k];
					map[i][j][k] -= map[i - 1][j][k - 1];

					map[i][j][k] += map[i - 1][j - 1][k - 1];
				}
			}
		}

		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				for (int k = 1; k <= c; k++)
				{
					for (int x = i; x <= a; x++)
					{
						for (int y = j; y <= b; y++)
						{
							for (int z = k; z <= c; z++)
							{
								long long sum = map[x][y][z];

								sum -= map[x][y][k - 1];
								sum -= map[x][j - 1][z];
								sum -= map[i - 1][y][z];

								sum += map[x][j - 1][k - 1];
								sum += map[i - 1][j - 1][z];
								sum += map[i - 1][y][k - 1];

								sum -= map[i - 1][j - 1][k - 1];

								result = max(result, sum);
							}
						}
					}
				}
			}
		}

		cout << result << endl;

		if (t) cout << endl;
	}
}