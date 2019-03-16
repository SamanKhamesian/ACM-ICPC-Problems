#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, k ,p , sum = 0;

	cin >> n >> k;

	int a[101] = { 0 };

	for (int i = 0; i < n; i++)
	{
		cin >> p;

		a[p]++;
	}

	for (int j = 99; j >= 91; j--)
	{
		for (int i = j; i >= 0; i = i - 10)
		{
			while (a[i] != 0)
			{
				int number = i;

				while ((number % 10) != 0 && k - (10 - (number % 10)) >= 0)
				{
					number++;

					k--;
				}

				if (number % 10 == 0)
				{
					a[number]++;
				}
				
				else
				{
					sum += (number / 10);
				}

				a[i]--;
			}
		}
	}

	for (int i = 100; i >= 0 ; i = i - 10)
	{
		while (a[i] != 0)
		{
			int number = i;

			while (number < 100 && k - (10 - (number % 10)) >= 0)
			{
				number++;

				k--;
			}

			sum += (number / 10);

			a[i]--;
		}
	}

	cout << sum << endl;
}
