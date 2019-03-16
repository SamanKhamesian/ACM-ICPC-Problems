#include <iostream>

using namespace std;

int main()
{
	int n, t;

	cin >> n >> t;

	if (t != 10)
	{
		for (int i = 0; i < n; i++)
		{
			cout << t;
		}

		cout << endl;

		return 0;
	}

	else
	{
		if (t == 10 && n != 1)
		{
			for (int i = 0; i < n - 1; i++)
			{
				cout << 1;
			}

			cout << 0 << endl;

			return 0;
		}

		else if (t == 10 && n == 1)
		{
			cout << -1 << endl;

			return 0;
		}
