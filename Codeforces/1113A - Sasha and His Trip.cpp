#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, v;
	int tank = 0;
	int sum = 0;

	cin >> n >> v;

	for (int i = 1; i < n; ++i)
	{
		if (n - i > tank)
		{
			int buy = min(n - i, v - tank);
			tank += buy;
			sum += (buy * i);
		}

		tank -= 1;
	}

	cout << sum << endl;
}