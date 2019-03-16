#include <iostream>

using namespace std;

int main()
{
	int n = 1;

	cin >> n;

	int table[10][10];

	for (int i = 0; i < n; i++)
	{
		table[0][i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		table[i][0] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			table[i][j] = table[i][j - 1] + table[i - 1][j];
			table[j][i] = table[i][j];
		}
	}

	cout << table[n - 1][n - 1];
}