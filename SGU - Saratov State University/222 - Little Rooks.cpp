#include <iostream>

using namespace std;

int main()
{
	int n, k;

	long long a = 1, b = 1;

	cin >> n >> k;

	if (n >= k)
	{
		for (int i = 0; i < k; i++)
		{
			a *= ((n - i)*(n - i));

			b *= (i + 1);
		}

		cout << a / b << endl;

		return 0;
	}

	else
	{
		cout << 0 << endl;
	}
}