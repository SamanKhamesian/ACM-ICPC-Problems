#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int k;

	cin >> k;

	if (k % 2 == 0)
	{
		cout << "NO" << endl;
	}

	else if (k > 1)
	{
		cout << "YES" << endl;

		cout << (k + 2) * 2 << " " << (((k + 2) * 2) * k) / 2 << endl;

		cout << 1 << " " << (k + 2) + 1 << endl;

		for (int i = 1; i <= k + 1; i++)
		{
			for (int j = i + 1; j <= k + 1; j++)
			{
				if (j != (i + (k + 1) / 2))
				{
					cout << i << " " << j << endl;
				}
			}
		}

		for (int i = 2; i <= k + 1; i++)
		{
			cout << i << " " << k + 2 << endl;
		}

		for (int i = k + 3; i <= (k + 2) * 2 - 1; i++)
		{
			for (int j = i + 1; j <= (k + 2) * 2 - 1; j++)
			{
				if (j != (i + (k + 1) / 2))
				{
					cout << i << " " << j << endl;
				}
			}
		}

		for (int i = k + 4; i <= (k + 2) * 2 - 1; i++)
		{
			cout << i << " " << (k + 2) * 2 << endl;
		}
	}

	else
	{
		cout << "YES" << endl;

		cout << 2 << " " << 1 << endl;

		cout << 1 << " " << 2 << endl;
	}
}