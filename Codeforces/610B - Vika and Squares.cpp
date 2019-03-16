#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long n, sum = 0, MIN = 1000000000007;

	cin >> n;

	vector <long long> index;

	vector <long long> numbers(n * 2);

	for (long long i = 0; i < n; i++)
	{
		cin >> numbers[i];

		numbers[i + n] = numbers[i];

		if (MIN >= numbers[i])
		{
			if (MIN > numbers[i])
			{
				index.clear();
			}

			MIN = numbers[i];

			index.push_back(i);

			index.push_back(n + i);
		}
	}

	sum += (n * MIN);

	if (index.size() == 2)
	{
		cout << sum + (n - 1) << endl;
	}

	else
	{
		sort(index.begin(), index.end());

		long long between = 0;

		for (long long i = 0; i < index.size() - 1; i++)
		{
			between = max(between, abs((index[i + 1] - index[i]) - 1));
		}

		cout << sum + between << endl;
	}

	return 0;
}