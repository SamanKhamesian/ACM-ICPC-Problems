#include <iostream>

using namespace std;

int main()
{
	int n, m = 0;

	cin >> n;

	int* a = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];

		if (a[i] != 0) m++;
	}

	if (m != 0)
	{
		int s = 1, e = 1;

		cout << "YES" << endl << m << endl;

		while (e <= n)
		{
			if (a[e] != 0)
			{
				while (e < n && a[e + 1] == 0)
				{
					e++;
				}

				cout << s << " " << e << endl;

				s = ++e;
			}

			else e++;
		}
	}

	else cout << "NO" << endl;
}