#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	for (int i = 2; (i * i) <= n; i++)
	{
		if (!(n % i))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int n, m = 0;

	cin >> n;

	if (n == 1 || n == 2) cout << 1 << endl;

	else cout << 2 << endl;

	for (int i = 2; i < n + 2; i++)
	{
		if (isPrime(i)) cout << 1 << " ";

		else cout << 2 << " ";
	}
}