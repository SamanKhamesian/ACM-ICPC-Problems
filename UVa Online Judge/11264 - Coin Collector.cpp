#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	int test, n;

	cin >> test;

	while (test--)
	{
		long long how = 0, sum = 0;

		cin >> n;

		long long* a = new long long[n];

		memset(a, 0, sizeof a);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < n; i++)
		{
			if ((i == n - 1 && sum < a[i]) || sum < a[i] && sum + a[i] < a[i + 1])
			{
				sum += a[i];

				how++;
			}
		}

		cout << how << endl;
	}
}