#include <iostream>
#include <vector>

using namespace std;

long long l, u;

#define MAX 10000001
#define MIN 0

vector<long long> p;
vector<bool> isPrime;

void setPrime()
{
	p.clear();
	isPrime.clear();
	isPrime.resize(MAX, true);

	isPrime[0] = isPrime[1] = false;

	for (long long i = 2; i < MAX; ++i)
	{
		if (isPrime[i])
		{
			for (long long j = i * i; j < MAX; j += i)
			{
				isPrime[j] = false;
			}

			p.push_back(i);
		}
	}
}

bool bePrime(long long x)
{
	if (x < MAX)
	{
		return isPrime[x];
	}

	else
	{
		for (long long i = 0; i < p.size() && p[i] * p[i] <= u; ++i)
		{
			if (x % p[i] == 0) return false;
		}

		return true;
	}
}

int main()
{
	setPrime();

	while (cin >> l >> u)
	{
		long long p, q, a, b, x, y;

		bool okP = false, okQ = false;

		p = q = a = b = x = y = l;

		long long minDist = MAX, maxDist = MIN;

		for (long long i = l; i <= u; ++i)
		{
			if (bePrime(i))
			{
				if (!okP)
				{
					okP = true;

					p = i;
				}

				else
				{
					okQ = true;

					q = i;

					if (q - p < minDist)
					{
						a = p;
						b = q;

						minDist = q - p;
					}

					if (q - p > maxDist)
					{
						x = p;
						y = q;

						maxDist = q - p;
					}

					p = q;
				}
			}
		}

		if (okQ)
		{
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, x, y);
		}

		else
		{
			cout << "There are no adjacent primes." << endl;
		}
	}
}