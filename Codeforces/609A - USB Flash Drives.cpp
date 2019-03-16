#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, file, how = 1, sum = 0;

	cin >> n >> file;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] + sum >= file)
		{
			cout << how << endl;

			return 0;
		}

		else
		{
			how++;

			sum += a[i];
		}
	}
}