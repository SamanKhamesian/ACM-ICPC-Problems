#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int n;
	long float minimum = 0;
	long float l;

	cin >> n >> l;

	long float* lamp = new long float[n];

	for (int i = 0; i < n; i++)
	{
		cin >> lamp[i];
	}

	sort(lamp, lamp + n);

	minimum = lamp[0];

	for (int i = 1; i < n; i++)
	{
		if (minimum < (lamp[i] - lamp[i - 1]) / 2)
		{
			minimum = (lamp[i] - lamp[i - 1]) / 2;
		}
	}

	if (minimum < (l - lamp[n - 1]))
	{
		minimum = (l - lamp[n - 1]);
	}

	printf("%.9f", minimum);
}