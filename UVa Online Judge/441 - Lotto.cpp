#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int s;

	bool first = false;

	cin >> s;

	while (s != 0)
	{
		int* a = new int[s];

		for (int i = 0; i < s; i++)
		{
			cin >> a[i];
		}

		if (first)
		{
			cout << endl;
		}

		else
		{
			first = true;
		}

		for (int i = 0; i < s; i++)
		{
			for (int j = i + 1; j < s; j++)
			{
				for (int k = j + 1; k < s; k++)
				{
					for (int p = k + 1; p < s; p++)
					{
						for (int q = p + 1; q < s; q++)
						{
							for (int r = q + 1; r < s; r++)
							{
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[p], a[q], a[r]);
							}
						}
					}
				}
			}
		}

		cin >> s;
	}
}