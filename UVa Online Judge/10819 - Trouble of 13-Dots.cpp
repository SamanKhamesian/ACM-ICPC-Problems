#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 10205

int main()
{
	long long W, n, U = 0;

	while (cin >> W >> n)
	{
		U = W;

		if (W > 1800)
		{
			U += 200;
		}

		int w[105];
		int v[105];
		int d[MAX];

		memset(w, 0, sizeof w);
		memset(v, 0, sizeof v);
		memset(d, 0, sizeof d);

		for (int i = 1; i <= n; i++)
		{
			cin >> w[i] >> v[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = U; j >= w[i]; j--)
			{
				if (j == w[i] || d[j - w[i]] > 0)
				{
					d[j] = max(d[j], d[j - w[i]] + v[i]);
				}
			}
		}

		int m = 0;

		if (W > 1800 && W <= 2000)
		{
			for (int i = 0; i <= W; i++)
			{
				m = max(m, d[i]);
			}

			for (int i = 2001; i <= U; i++)
			{
				m = max(m, d[i]);
			}
		}

		else
		{
			for (int i = 0; i <= U + 1; i++)
			{
				m = max(m, d[i]);
			}
		}

		cout << m << endl;
	}
}