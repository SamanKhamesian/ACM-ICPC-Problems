#include <iostream>

using namespace std;

int main()
{
	int n, m, k, i, j;
	int counter = 0;

	cin >> n >> m >> k;

	bool map[1002][1002] = { false };

	for (int c = 1; c <= k; c++)
	{
		cin >> i >> j;

		map[i][j] = true;

		if (map[i][j] && map[i - 1][j] && map[i][j - 1] && map[i - 1][j - 1])
		{
			if (counter == 0)
			{
				counter = c;
			}
		}

		else if (map[i][j] && map[i - 1][j] && map[i][j + 1] && map[i - 1][j + 1])
		{
			if (counter == 0)
			{
				counter = c;
			}
		}

		else if (map[i][j] && map[i][j - 1] && map[i + 1][j] && map[i + 1][j - 1])
		{
			if (counter == 0)
			{
				counter = c;
			}
		}

		else if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
		{
			if (counter == 0)
			{
				counter = c;
			}
		}
	}

	cout << counter;
}