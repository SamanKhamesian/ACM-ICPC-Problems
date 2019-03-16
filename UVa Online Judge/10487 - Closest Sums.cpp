#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, c = 1;

	cin >> n;

	while (n != 0)
	{
		int* a = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		cin >> m;

		int* q = new int[m];

		for (int i = 0; i < m; i++)
		{
			cin >> q[i];
		}

		int sum = 0, ans = 0, minDis = 900000000;

		printf("Case %d:\n", c);

		for (int k = 0; k < m; k++)
		{
			sum = 0;
			ans = 0;
			minDis = 900000000;

			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					sum = a[i] + a[j];

					if (abs(q[k] - a[i] - a[j]) < minDis)
					{
						minDis = abs(q[k] - a[i] - a[j]);

						ans = sum;
					}
				}
			}

			printf("Closest sum to %d is %d.\n", q[k], ans);
		}

		c++;

		cin >> n;
	}
}