#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int total;

	int d1 = 0;
	int d2 = 0;
	int d3 = 0;

	int min1, min2, min3;
	int max1, max2, max3;

	cin >> total;
	cin >> min1 >> max1;
	cin >> min2 >> max2;
	cin >> min3 >> max3;

	d1 = min1;
	d2 = min2;
	d3 = min3;

	while (d1 + d2 + d3 != total)
	{
		if (d1 < max1)
		{
			d1++;
			continue;
		}

		if (d2 < max2)
		{
			d2++;
			continue;
		}

		if (d3 < max3)
		{
			d3++;
			continue;
		}
	}

	cout << d1 << " " << d2 << " " << d3;
}