#include <iostream>

using namespace std;

int n;

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0) return false;
	}

	return true;
}

int main()
{
	while (cin >> n, n != 0)
	{
		bool ok = false;

		for (int i = 2; i <= n; ++i)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				cout << n << " = " << i << " + " << n - i << endl;

				ok = true;

				break;
			}
		}

		if (!ok)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
}