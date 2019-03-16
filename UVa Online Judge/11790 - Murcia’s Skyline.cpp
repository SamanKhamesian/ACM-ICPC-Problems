#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100000

void show(int c, int inc, int dec)
{
	if (inc >= dec)
	{
		cout << "Case " << c << ". Increasing (" << inc << "). Decreasing (" << dec << ")." << endl;
	}

	else
	{
		cout << "Case " << c << ". Decreasing (" << dec << "). Increasing (" << inc << ")." << endl;
	}
}

int main()
{
	int t, n, c = 1;

	cin >> t;

	while (t--)
	{
		cin >> n;

		int a[2][MAX];

		int LIS[MAX];
		int LDS[MAX];

		memset(LIS, 0, sizeof LIS);
		memset(LDS, 0, sizeof LDS);
		memset(a, 0, sizeof a);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			LIS[i] = LDS[i] = a[1][i];

			for (int j = 0; j < i; j++)
			{
				if (a[0][i] > a[0][j])
				{
					LIS[i] = max(LIS[j] + a[1][i], LIS[i]);
				}

				if (a[0][i] < a[0][j])
				{
					LDS[i] = max(LDS[j] + a[1][i], LDS[i]);
				}
			}
		}

		int inc = 0, dec = 0;

		for (int i = 0; i < n; i++)
		{
			inc = max(inc, LIS[i]);
			dec = max(dec, LDS[i]);
		}

		show(c++, inc, dec);
	}
}