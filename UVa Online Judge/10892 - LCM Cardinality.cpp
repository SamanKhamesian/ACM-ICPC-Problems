#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;

long long gcd(long long a, long b)
{
	if (b == 0) return a;

	else return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a, b)) * b;
}

int main()
{
	while (cin >> n, n != 0)
	{
		int ans = 1;

		vector<long long> div;

		for (long long i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				div.push_back(i);

				if (i != (n / i)) div.push_back(n / i);
			}
		}

		for (int i = 0; i < div.size(); i++)
		{
			for (int j = i; j < div.size(); j++)
			{
				if (i != j)
				{
					if (lcm (max(div[i], div[j]), min(div[i], div[j])) == n)
					{
						ans++;
					}
				}
			}
		}

		cout << n << " " << ans << endl;
	}
}