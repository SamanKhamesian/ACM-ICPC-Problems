#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	long long s, how = 0;

	while (cin >> s)
	{
		how = 0;

		while (s != 0)
		{
			if (s % 2 == 0) s /= 2;

			else
			{
				if (s % 4 == 3)
				{
					if (s == 3) s--;

					else s++;
				}

				else s--;
			}

			how++;
		}

		cout << how << endl;
	}
}