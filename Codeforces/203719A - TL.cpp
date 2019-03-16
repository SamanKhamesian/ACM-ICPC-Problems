#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, Min, Max;

	cin >> n >> m;

	int* an = new int[n];

	int* am = new int[m];

	for (int i = 0; i < n; i++)
	{
		cin >> an[i];
	}

	sort(an, an + n);

	Max = an[n - 1];

	for (int i = 0; i < m; i++)
	{
		cin >> am[i];
	}

	sort(am, am + m);

	Min = am[0];

	for (int i = Max; i < Min; i++)
	{
		if (i >= Max && i < Min && i >= an[0] * 2)
		{
			cout << i << endl;

			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}