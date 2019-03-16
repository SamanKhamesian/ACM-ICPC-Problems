#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;

	long x = 0;

	int counter = 0;

	cin >> n;

	long* t = new long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}

	sort(t, t + n);

	for (int j = 0; j < n; j++)
	{
		if (t[j] >= x)
		{
			x += t[j];
			counter++;
		}

		else
			t[j] = 0;
	}

	cout << counter;
}