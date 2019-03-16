#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, how = 0, tt = 0;

	bool zero = false;

	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] == 0)
		{
			zero = true;
		}

		how += a[i];
	}

	how = how % 3;

	if (!zero)
	{
		cout << -1;

		return 0;
	}

	if (!how && zero)
	{
		sort(a, a + n);

		reverse(a, a + n);

		if (a[0] == 0)
		{
			cout << 0;

			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}

		return 0;
	}

	if (how && zero)
	{
		if (how == 1)
		{
			sort(a, a + n);

			for (int i = 0; i < n ; i++)
			{
				if (a[i] == 1 || a[i] == 4 || a[i] == 7)
				{
					a[i] = 0;

					sort(a, a + n);

					reverse(a, a + n);

					if (a[0] == 0)
					{
						cout << 0;

						return 0;
					}

					for (int j = 0; j < n - 1; j++)
					{
						cout << a[j];
					}

					return 0;
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (a[i] == 2 || a[i] == 5 || a[i] == 8)
				{
					a[i] = 0;

					tt++;

					if (tt == 2)
					{
						sort(a, a + n);

						reverse(a, a + n);

						if (a[0] == 0)
						{
							cout << 0;

							return 0;
						}

						for (int j = 0; j < n - 2; j++)
						{
							cout << a[j];
						}

						return 0;
					}
				}
			}
		}

		tt = 0;

		if (how == 2)
		{
			sort(a, a + n);

			for (int i = 0; i < n; i++)
			{
				if (a[i] == 2 || a[i] == 5 || a[i] == 8)
				{
					a[i] = 0;

					sort(a, a + n);

					reverse(a, a + n);

					if (a[0] == 0)
					{
						cout << 0;

						return 0;
					}

					for (int j = 0; j < n - 1; j++)
					{
						cout << a[j];
					}

					return 0;
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (a[i] == 1 || a[i] == 4 || a[i] == 7)
				{
					a[i] = 0;

					tt++;

					if (tt == 2)
					{
						sort(a, a + n);

						reverse(a, a + n);

						if (a[0] == 0)
						{
							cout << 0;

							return 0;
						}

						for (int j = 0; j < n - 2; j++)
						{
							cout << a[j];
						}

						return 0;
					}
				}
			}
		}
	}
}