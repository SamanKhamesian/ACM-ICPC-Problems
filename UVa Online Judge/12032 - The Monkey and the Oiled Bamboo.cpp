#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int binarySearch(int myLow, int a[], int n)
{
	int ans = 0;

	int l = myLow, h = 10000005;

	while (l < h)
	{
		int mid = (l + h) / 2;

		int temp = mid;

		bool ok = true;

		for (int i = 1; i <= n; i++)
		{
			if (a[i] - a[i - 1] > temp)
			{
				ok = false;

				break;
			}

			if (a[i] - a[i - 1] == temp) temp--;
		}

		if (ok)
		{
			h = mid;

			ans = mid;
		}

		else
		{
			l = mid;

			if (mid + 1 == h) break;
		}
	}

	return ans;
}

int main()
{
	int test, t = 1;

	cin >> test;

	while (test--)
	{
		int n, myLowerBound = 0;

		cin >> n;

		int* a = new int[n + 1];

		a[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];

			myLowerBound = max(myLowerBound, a[i] - a[i - 1]);
		}

		cout << "Case " << t++ << ": " << binarySearch(myLowerBound, a, n) << endl;
	}
}