#include <algorithm>
#include <iostream>

using namespace std;

long long fibo[42] = { 0, 1};


int main()
{
	int k;

	long long sum = 1;

	cin >> k;

	if (k == 0)
	{
		cout << 0 << endl;
	}

	else if (k == 1)
	{
		cout << 1 << endl;
	}

	else
	{
		for (int i = 2; i <= k; i++)
		{
			fibo[i] = fibo[i - 1] + fibo[i - 2];

			sum += fibo[i];
		}

		cout << sum << endl;
	}
}