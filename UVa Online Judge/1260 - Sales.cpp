#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		int size, b = 0;

		cin >> size;

		int *a = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> a[i];
		}

		for (int i = 1; i < size; i++)
		{
			int temp = 0;

			for (int j = 0; j < i; j++)
			{
				if (a[j] <= a[i])
				{
					temp++;
				}
			}

			b += temp;
		}

		cout << b << endl;
	}
}