#include <iostream>

using namespace std;

unsigned long long n, m;

bool table[1001][1001];

int main()
{
	cin >> n >> m;

	int* numbers = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		cin >> numbers[i];
	}

	if (n >= m)
	{
		cout << "YES" << endl;

		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		table[numbers[i] % m][i] = true;

		for (int j = 0; j < m; j++)
		{
			if (table[j][i - 1])
			{
				table[j][i] = true;

				table[(j + numbers[i]) % m][i] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (table[0][i])
		{
			cout << "YES" << endl;

			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}