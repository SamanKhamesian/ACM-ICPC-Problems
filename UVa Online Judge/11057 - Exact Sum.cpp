#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	int n, sum = 0;

	while (cin >> n)
	{
		int minimum = 100000000;

		int one = 0, two = 0;

		vector<int> price;

		for (int i = 0; i < n; i++)
		{
			int x;

			cin >> x;

			price.push_back(x);
		}

		cin >> sum;

		sort(price.begin(), price.end());

		while (!price.empty())
		{
			int first = price.front();

			int second = sum - first;

			price.erase(price.begin());

			vector<int> :: iterator pos = find(price.begin(), price.end(), second);

			if (pos != price.end())
			{
				if (abs(first - second) < minimum)
				{
					one = min(first, second);
					two = max(first, second);

					minimum = abs(first - second);
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", one, two);
	}
}