#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int kadane1D(int *a, int n)
{
	int ans = -10000000, sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];

		ans = max(ans, sum);

		if (sum < 0)
		{
			sum = 0;
		}
	}

	return ans;
}

int main()
{
	int n;

	cin >> n;

	while (n != 0)
	{
		int* a = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int result = kadane1D(a, n);

		if (result > 0)
		{
			cout << "The maximum winning streak is " << result << "." << endl;
		}

		else
		{
			cout << "Losing streak." << endl;
		}

		cin >> n;
	}
}