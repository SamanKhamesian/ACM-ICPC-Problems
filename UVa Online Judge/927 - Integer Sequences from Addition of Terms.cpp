#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long power(long long n, long long t)
{
	if (t == 0)
	{
		return 1;
	}

	else if (t == 1)
	{
		return n;
	}

	else
	{
		long long temp = power(n, t / 2);

		if (t % 2 == 0)
		{
			return temp * temp;
		}

		else
		{
			return temp * temp * n;
		}
	}
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		int p, d, k;

		cin >> p;

		int* f = new int[p + 1];

		for (int i = 0; i < p + 1; i++)
		{
			cin >> f[i];
		}

		cin >> d >> k;

		int ind = 0;

		long long range = 0;

		while (range <= k)
		{
			ind++;

			range += (d * ind);
		}

		range -= (d * ind);

		if (range == k)
		{
			ind--;
		}

		vector <long long> a;

		for (int i = 1; i <= ind; i++)
		{
			long long temp = 0;

			for (int j = 0; j < p + 1; j++)
			{
				temp += (f[j] * power(i, j));
			}

			a.push_back(temp);
		}

		cout << a[a.size() - 1] << endl;
	}
}