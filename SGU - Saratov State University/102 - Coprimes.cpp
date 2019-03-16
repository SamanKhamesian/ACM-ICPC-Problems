#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;

	else return gcd(b, a % b);
}

int main()
{
	int n, how = 1;

	cin >> n;

	for (int i = 2; i < n; i++)
	{
		if (gcd(n, i) == 1)
		{
			how++;
		}
	}

	cout << how << endl;
}