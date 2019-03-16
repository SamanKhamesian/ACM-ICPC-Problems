#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, m, k, i;

	cin >> n >> m >> k;

	i = 2 * m;

	for (int j = 1; j <= n; j++)
	{
		if (k <= i * j && k >= (i * (j - 1)) + 1)
		{
			cout << j << " ";

			if (k % 2 == 0)
			{
				cout << (k - ((i * (j - 1)) + 1) - 1) / 2 + 1 << " " << 'R' << endl;
			}

			else
			{
				cout << (k - ((i * (j - 1)) + 1)) / 2 + 1 << " " << 'L' << endl;
			}

			break;
		}
	}
}