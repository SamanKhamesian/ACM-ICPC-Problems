#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int TC, a, b, row[8], lineCounter;

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
	if (c == 8 && row[b] == a)
	{
		printf("%2d      %d %d %d %d %d %d %d %d\n", lineCounter++, row[0] + 1, row[1] + 1, row[2] + 1, row[3] + 1, row[4] + 1, row[5] + 1, row[6] + 1, row[7] + 1);
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
	cin >> TC;

	bool first = false;

	while (TC--)
	{
		cin >> a >> b;

		if (first) cout << endl;
		else first = true;

		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

		lineCounter = 1;
		memset(row, 0, sizeof row);

		a--;
		b--;

		backtrack(0);
	}
}