#include <iostream>

using namespace std;

bool isPrime(long n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long n;

	cin >> n;

	if (isPrime(n))
	{
		cout << 1 << endl;

		cout << n << endl;

		return 0;
	}

	else if (isPrime(n - 2))
	{
		cout << 2 << endl;

		cout << 2 << " " << n - 2 << endl;

		return 0;
	}

	else if (isPrime(n - 4))
	{
		cout << 3 << endl;

		cout << 2 << " " << " " << 2 << " " << n - 4 << endl;

		return 0;
	}

	else
	{
		for (int i = (n - 3) / 2; i < n - 3; i++)
		{
			if (isPrime(i) && isPrime(n - 3 - i))
			{
				cout << 3 << endl;

				cout << 3 << " " << i << " " << n - i - 3 << endl;

				return 0;
			}
		}
	}
}