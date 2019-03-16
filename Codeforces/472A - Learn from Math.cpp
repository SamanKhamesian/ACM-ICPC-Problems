#include <iostream>

using namespace std;

bool isPrime(int n)
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
	unsigned long n;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		if (!isPrime(i) && !isPrime(n - i))
		{
			cout << i << " " << n - i;

			return 0;
		}
	}
}