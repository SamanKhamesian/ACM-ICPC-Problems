#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cc = 1, minimum, temp, num = 0, test[8], row[8], dp[92][8];

bool place(int r, int c)
{
	for (int pre = 0; pre < c; pre++)
	{
		if (row[pre] == r || (abs(row[pre] - r) == abs(c - pre))) return false;
	}

	return true;
}

void backtrack(int c)
{
	if (c == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			dp[num][i] = row[i] + 1;
		}

		num++;
	}

	for (int r = 0; r < 8; r++)
	{
		if (place(r, c))
		{
			row[c] = r;

			backtrack(c + 1);
		}
	}
}

int main()
{
	memset(dp, 0, sizeof dp);
	memset(row, 0, sizeof row);

	backtrack(0);

	while (cin >> test[0] >> test[1] >> test[2] >> test[3] >> test[4] >> test[5] >> test[6] >> test[7])
	{
		temp = 0;
		minimum = 100000000;

		for (int i = 0; i < 92; i++)
		{
			temp = 0;

			for (int j = 0; j < 8; j++)
			{
				if (dp[i][j] != test[j])
				{
					temp++;
				}
			}

			minimum = min(minimum, temp);
		}

		cout << "Case " << cc << ": " << minimum << endl;

		cc++;
	}
	
}