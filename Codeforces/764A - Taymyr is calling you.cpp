#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int n, int m)
{
	if (m == 0) return n;

	else return gcd(m, n % m);
}

int main()
{
	int n, m, z;

	cin >> n >> m >> z;

	int gcd_num = gcd(max(n, m), min(m, n));

	cout << (z * gcd_num) / (n * m) << endl;
}
