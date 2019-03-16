#include <iostream>

using namespace std;

int main()
{
	unsigned long long n, p, q, result;

	cin >> n;

	if (n % 2 == 1)
	{
        p = (n + 1) / 2;

		q = (n - 1) / 2;
	}

	else p = q = n / 2;

	result = (q * (q + 1)) - (p * p);

	cout << result;
}
