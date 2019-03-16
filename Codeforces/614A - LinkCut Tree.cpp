#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int lg(long long a, long double k)
{
	int sum = 0;

	while (a > 0)
	{
		a /= k;

		sum++;
	}

	return sum;
}

int main()
{
	int index = 0;

	bool ok = false;

	long double k;

	long long l, r, sum = 1, kk;

	cin >> l >> r >> k;

	int high = lg(r, k);

	kk = (long long)k;

	while ((long long)pow(k, index) <= r && index < high)
	{
		if ((long long)pow(k, index) >= l && (long long)pow(k, index) <= r)
		{
			ok = true;

			cout << sum << " ";
		}

		sum *= kk;

		index++;
	}

	if (!ok)
	{
		cout << -1;
	}

	return 0;
}