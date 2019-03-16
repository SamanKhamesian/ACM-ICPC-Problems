#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	long long sum = 0;

	long long t, n;

	cin >> t;

	while (t--)
	{
		cin >> n;

		sum = 0;

		long long i = 1;

		for (i = 1; i <= n; i <<= 1)
		{

		}

		sum = -2 * i + ((n * (n + 1)) / 2) + 2;

		cout << sum << endl;
	}
}