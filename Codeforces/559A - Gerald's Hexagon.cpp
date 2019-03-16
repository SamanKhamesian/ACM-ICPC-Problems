#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	bool ok = true;

	int a[6], sum = 0;

	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}

	while (ok)
	{
		ok = false;

		for (int i = 0; i < 6; i++)
		{
			if (a[i] > 1 && a[(i + 2) % 6] > 1)
			{
				sum += (a[i + 1] * 2 + 1);

				a[i + 1]++;

				a[i]--;

				a[i + 2]--;

				ok = true;

				break;
			}
		}
	}

	sort(a, a + 6);

	cout << (a[5] * 2 + 1) * 2 + sum << endl;
}