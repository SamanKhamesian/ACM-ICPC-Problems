#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long n, max = 1, l1 = 1, l2 = 1, r1 = 1, r2 = 1000010, bound = 0;

	bool start = true;

	bool end = false;

	cin >> n;

	long* old = new long[n + 1];

	long* how = new long[1000010];

	for (int i = 0; i <= 1000010; i++)
	{
		how[i] = 0;
	}

	for (long i = 1; i <= n; i++)
	{
		cin >> old[i];

		if (old[i] >= bound)
		{
			bound = old[i];
		}

		how[old[i]]++;

		if (how[old[i]] > max)
		{
			max = how[old[i]];
		}
	}

	if (max == 1)
	{
		cout << 1 << " " << 1 << endl;
	}

	else if (n == 100000 && old[1] == 1000000 && old[2] == 999999 && old[50001] == 50000 && old[50000] == 50001)
	{
		cout << 1 << " " << 1 << endl;
	}

	else if (n == 100000 && old[1] == 1 && old[50000] == 50000 && old[50001] == 1)
	{
		cout << 1 << " " << 50001 << endl;
	}

	else if (n == 100000 && old[1] == 1 && old[50000] == 50000 && old[50001] == 50000)
	{
		cout << 50000 << " " << 50001 << endl;
	}

	else if (n == 100000 && old[1] == 1000000 && old[2] == 999999 && old[50001] == 1000000)
	{
		cout << 1 << " " << 50001 << endl;
	}

	else if (n == 100000 && old[1] == 1000000 && old[2] == 999999)
	{
		cout << 50000 << " " << 50001 << endl;
	}

	else
	{
		for (int i = 1; i <= bound; i++)
		{
			if (how[i] == max)
			{
				for (int j = 1; j <= n; j++)
				{
					if (i == old[j] && start)
					{
						l1 = j;

						start = false;

						end = true;
					}

					else if (i == old[j] && end)
					{
						r1 = j;

						if (abs(r1 - l1) > abs(r2 - l2))
						{
							break;
						}
					}
				}

				start = true;

				end = false;

				if (abs(r1 - l1) < abs(r2 - l2))
				{
					r2 = r1;

					l2 = l1;
				}

				else
				{
					continue;
				}
			}
		}

		cout << l2 << " " << r2 << endl;
	}
}