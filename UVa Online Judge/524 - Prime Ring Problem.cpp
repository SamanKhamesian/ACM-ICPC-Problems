#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n, ans[20];

bool isPrime(int number)
{
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void backtrack(bool visit[20], int ind, int cur)
{
	ans[ind] = cur;

	if (ind == n && isPrime(1 + ans[ind]))
	{
		cout << ans[1];

		for (int i = 2; i <= n; i++)
		{
			cout << " " << ans[i];
		}

		cout << endl;
	}

	if (cur % 2 == 1)
	{
		for (int i = 2; i <= n; i += 2)
		{
			if (!visit[i] && isPrime(i + cur))
			{
				visit[i] = true;

				backtrack(visit, ind + 1, i);

				visit[i] = false;
			}
		}
	}

	else
	{
		for (int i = 3; i <= n; i += 2)
		{
			if (!visit[i] && isPrime(i + cur))
			{
				visit[i] = true;

				backtrack(visit, ind + 1, i);

				visit[i] = false;
			}
		}
	}
}

int main()
{
	int ccc = 1;

	ios::sync_with_stdio(0);

	while (cin >> n)
	{
		if (ccc != 1)
		{
			cout << endl;
		}

		cout << "Case " << ccc << ":" << endl;

		bool visit[20];
		memset(visit, 0, sizeof visit);
		memset(ans, 0, sizeof ans);

		backtrack(visit, 1, 1);

		ccc++;
	}
}