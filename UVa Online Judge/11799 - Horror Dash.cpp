#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int test, counter = 1;

	cin >> test;

	while (test--)
	{
		int how, m = 0;

		cin >> how;

		int * a = new int[how];

		for (int i = 0; i < how; i++)
		{
			cin >> a[i];

			m = max(m, a[i]);
		}

		cout << "Case " << counter << ": " << m << endl;

		counter++;
	}
}