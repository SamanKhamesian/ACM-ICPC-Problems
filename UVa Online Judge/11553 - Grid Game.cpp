#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int TC, n, ans, minimum;
int col[10], table[10][10];

bool place(int r, int c)
{
	for (int pre = 0; pre < r; pre++)
	{
		if (col[pre] == c)
		{
			return false;
		}
	}

	return true;
}

void backTrack(int r)
{
	if (r == n)
	{
		ans = 0;

		for (int i = 0; i < n; i++)
		{
			ans += table[i][col[i]];
		}

		minimum = min(minimum, ans);
	}

	for (int c = 0; c < n; c++)
	{
		if (place(r, c))
		{
			col[r] = c;

			backTrack(r + 1);
		}
	}
}

int main()
{
	cin >> TC;

	while (TC--)
	{
		cin >> n;

		minimum = 100000000;
		ans = 0;

		memset(table, 0, sizeof table);

		memset(col, 0, sizeof col);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> table[i][j];
			}
		}

		backTrack(0);

		cout << minimum << endl;
	}
}