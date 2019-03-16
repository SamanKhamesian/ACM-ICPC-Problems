#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

#define MAX 0
#define MIN 999999999
#define MOD 1000000007

int main()
{
	int n, ones = 0;

	long long sum = 1;

	cin >> n;

	int a[110];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] == 1)
		{
			ones++;
		}
	}

	if (ones == 0)
	{
		cout << 0 << endl;
	}

	else if (ones == 1)
	{
		cout << 1 << endl;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (a[j] == 1)
					{
						sum *= (j - i);

						break;
					}
				}
			}
		}

		cout << sum << endl;
	}

	return 0;
}