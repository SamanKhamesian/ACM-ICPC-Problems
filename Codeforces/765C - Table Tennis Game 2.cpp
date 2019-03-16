#include <iostream>

using namespace std;

int main()
{
	long long k, a, b;

	cin >> k >> a >> b;

	if ((a < k && b % k) || (b < k && a % k)) cout << -1 << endl;

	else cout << (a / k) + (b / k) << endl;
}