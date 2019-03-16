#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAX 10001

int n, m, k, how = 0;

vector<int> prime;

int test[9974] = { 0 };

char p[MAX];

void seive()
{
	memset(p, 1, sizeof p);

	prime.push_back(2);

	for (int i = 3; i < MAX; i += 2)
	{
		if (p[i])
		{
			prime.push_back(i);

			for (int j = i + i; j < MAX; j += i)
			{
				p[j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	seive();

	for (int i = 0; i < prime.size(); i++)
	{
		if (k % prime[i] == 0)
		{
			test[prime[i]]++;

			k /= prime[i];

			i--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int x;

		cin >> x;

		bool ok = true;

		int current[9974] = { 0 };

		for (int j = 0; j < prime.size(); j++)
		{
			if (x % prime[j] == 0)
			{
				current[prime[j]]++;

				x /= prime[j];

				j--;
			}
		}

		for (int j = 0; j < prime.size(); j++)
		{
			if (current[prime[j]] * m < test[prime[j]])
			{
				ok = false;

				break;
			}
		}

		if (ok)
		{
			how++;
		}
	}

	cout << how << endl;
}