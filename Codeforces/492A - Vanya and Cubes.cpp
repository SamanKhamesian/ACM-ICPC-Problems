#include <iostream>

using namespace std;

int main()
{
	int i, n, sum = 0;

	cin >> n;

	for (i = 0; sum <= n ; i++)
	{
		for (int j = 1; j <= i && sum <= n; j++)
		{
			sum += j;
		}
	}

	cout << i - 2;
}