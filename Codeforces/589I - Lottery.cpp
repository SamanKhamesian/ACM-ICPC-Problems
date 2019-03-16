#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, r = 0, avg = 0;

	cin >> n >> k;

	avg = n / k;

	int a[110] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		int x;

		cin >> x;

		a[x]++;

		if (a[x] > avg)
			r++;
	}

	cout << r << endl;
}