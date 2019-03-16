#include <iostream>
#include <algorithm>

using namespace std;

long long power(int a, int b)
{
	if (b == 0)
		return 1;

	else if (b == 1)
		return a;

	else
	{
		long long temp = power(a, b / 2);

		if (b % 2 == 0)
			return temp * temp;

		else
			return temp * temp * a;
	}
}

int main()
{
	long long start, end, sum = 0, current = 0;

	cin >> start >> end;

	for (int i = 1; i <= 60; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i - j > 1)
			{
				current = power(2, i) - 1 - power(2, j);

				if (current >= start && current <= end)
				{
					sum++;
				}
			}
		}
	}

	cout << sum << endl;
}