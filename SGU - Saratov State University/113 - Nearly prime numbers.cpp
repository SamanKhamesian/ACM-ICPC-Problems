#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000000

char Prime[MAX];

vector<int> primes;

void seive()
{
	memset(Prime, 1, sizeof Prime);

	primes.push_back(2);

	for (int i = 3; i < MAX; i += 2)
	{
		if (Prime[i])
		{
			primes.push_back(i);

			for (int j = 2; j * i < MAX; j++)
			{
				Prime[j * i] = 0;
			}
		}
	}
}

int main()
{
	int test, n, ok = 0;

	cin >> test;

	seive();

	while (test--)
	{
		ok = 0;

		vector<int> wh;

		cin >> n;

		if (n == 0)
		{
			cout << "No" << endl;
		}

		else
		{
			for (int i = 0; i < primes.size(); i++)
			{
				if (n % primes[i] == 0)
				{
					int temp = n;

					wh.push_back(primes[i]);

					while (temp % primes[i] == 0)
					{
						ok++;

						temp /= primes[i];
					}
				}
			}

			if (ok > 2)
			{
				cout << "No" << endl;
			}

			else
			{
				for (int i = 0; i < wh.size(); i++)
				{
					for (int j = 0; j < primes.size(); j++)
					{
						if ((n / wh[i] != 1) && (n / wh[i]) != primes[j] && (n / wh[i]) % primes[j] == 0)
						{
							ok++;
						}
					}
				}

				if (ok == 2 || (ok == 1 && n > MAX))
				{
					cout << "Yes" << endl;
				}

				else
				{
					cout << "No" << endl;
				}
			}
		}
	}
}
