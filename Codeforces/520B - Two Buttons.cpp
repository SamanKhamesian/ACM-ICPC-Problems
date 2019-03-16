#include <iostream>

using namespace std;

int main()
{
	int n, m, sum = 0;

	cin >> n >> m;

	while (m != n)
	{
		if (m < n)
			m++;

		else
		{
			if (m%2 == 0)
				m /= 2;
			else
				m++;
		}

		sum++;
	}

	cout << sum;
}