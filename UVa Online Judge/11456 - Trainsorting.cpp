#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

#define MAX 2010

int main()
{
	int t, n, m = 0;

	cin >> t;

	while (t--)
	{
		cin >> n;

		int ARY[MAX];
		int LIS[MAX];
		int LDS[MAX];

		memset(LIS, 0, sizeof LIS);
		memset(LDS, 0, sizeof LDS);

		for (int i = 0; i < n; i++)
		{
			cin >> ARY[i];
		}

		LIS[0] = LDS[0] = 1;

		reverse(ARY, ARY + n);

		for (int i = 0; i < n; i++)
		{
			LIS[i] = LDS[i] = 1;

			for (int j = 0; j < i; j++)
			{
				if (ARY[i] > ARY[j] && LIS[i] < LIS[j] + 1)
				{
					LIS[i] = LIS[j] + 1;
				}

				if (ARY[i] < ARY[j] && LDS[i] < LDS[j] + 1)
				{
					LDS[i] = LDS[j] + 1;
				}
			}
		}

		m = 0;

		for (int i = 0; i < n; i++)
		{
			m = max(m, LIS[i] + LDS[i] - 1);
		}

		cout << m << endl;
	}
}