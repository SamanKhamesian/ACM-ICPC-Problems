#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	bool* bulbs = new bool[m];

	for (int i = 0; i < m; i++)
	{
		bulbs[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		int x;

		cin >> x;

		for (int j = 0; j < x; j++)
		{
			int index;

			cin >> index;

			bulbs[index - 1] = true;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!bulbs[i])
		{
			cout << "NO" << endl;

			return 0;
		}
	}

	cout << "YES" << endl;
}