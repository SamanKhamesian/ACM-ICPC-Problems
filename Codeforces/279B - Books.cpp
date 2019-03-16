#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n, t;

	int j = 0, how = 0, maximum = 0;

	cin >> n >> t;

	int* times = new int[n];

	for (int i = 0; i < n; i++)
		cin >> times[i];

	for (int i = 0; i < n; i++)
	{
		for (; j < n && how + times[j] <= t; j++)
			how += times[j];

		how -= times[i];

		if (j - i > maximum)
			maximum = j - i;
	}

	cout << maximum;
}











