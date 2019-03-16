#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;

	else return gcd(b, a % b);
}

int main()
{
	string s;

	int t, n, a[99], ans = 0;

	getline(cin, s);
	istringstream is(s);

	is >> t;

	while (t--)
	{
		getline(cin, s);
		istringstream is(s);

		ans = n = 0;

		while (is >> a[n]) ++n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					ans = max(ans, gcd(max(a[i], a[j]), min(a[i], a[j])));
				}
			}
		}

		cout << ans << endl;
	}
}