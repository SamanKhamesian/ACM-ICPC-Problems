#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int TC, n, p;
bool canMake[1010];

int main()
{
	cin >> TC;

	while (TC--)
	{
		cin >> n;

		cin >> p;

		int* value = new int[p];

		memset(canMake, false, sizeof canMake);

		for (int i = 0; i < p; i++)
		{
			cin >> value[i];
		}

		canMake[0] = true;

		sort(value, value + p);

		for (int i = 0; i < p; i++)
		{
			for (int j = 1001; j >= 0; j--)
			{
				if (j - value[i] >= 0 && canMake[j - value[i]]) canMake[j] = true;
			}
		}

		if (canMake[n]) cout << "YES" << endl;

		else cout << "NO" << endl;
	}
}