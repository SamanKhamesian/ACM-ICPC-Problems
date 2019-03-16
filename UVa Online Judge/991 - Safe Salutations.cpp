#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long cal(long long n)
{
	long long Ck = 1, Cn;

	for (long long i = 1; i <= n; i++)
	{
		Cn = ((2 * (2 * i - 1)) / (i + 1)) * Ck;

		Ck = Cn;
	}

	return Ck;
}

int main()
{
	long long n;

	cin >> n;

	cout << cal(n) << " " << n + 1 << endl;
}
