#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, a;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		sum += a;
	}

	if (sum % n == 0)
	{
		cout << n << endl;

		return 0;
	}

	else
	{
		cout << n - 1 << endl;

		return 0;
	}
}