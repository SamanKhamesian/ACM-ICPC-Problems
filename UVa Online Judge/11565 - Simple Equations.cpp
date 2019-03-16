#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		bool found = false;
		int a, b, c;

		cin >> a >> b >> c;

		for (int x = -100; x <= 100; x++)
		{
			if ((x * x) <= c && !found)
			{
				for (int y = -100; y <= 100; y++)
				{
					if ((x * x) + (y * y) <= c && !found && y != x)
					{
						for (int z = -100; z <= 100; z++)
						{
							if (z != x && y != z && !found && (x + y + z) == a && (x * y * z) == b && ((x * x) + (y * y) + (z * z)) == c)
							{
								cout << x << " " << y << " " << z << endl;

								found = true;
							}
						}
					}
				}
			}
		}

		if (!found)
		{
			cout << "No solution." << endl;
		}
	}
}