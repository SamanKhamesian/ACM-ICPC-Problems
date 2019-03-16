#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, counter = 0, start = 0;

	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (sum < n)
	{
		if (start == 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] <= sum && a[i] != -1)
				{
					sum++;

					a[i] = -1;
				}
			}

			start = n - 1;

			if (counter)
			{
				counter++;
			}
		}

		else
		{
			for (int i = start; i >= 0; i--)
			{
				if (a[i] <= sum && a[i] != -1)
				{
					sum++;

					a[i] = -1;
				}
			}

			start = 0;

			counter++;
		}
	}

	cout << counter << endl;
}