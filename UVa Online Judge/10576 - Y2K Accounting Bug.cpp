#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

long long s, d, maximum, per;

bool mustNegetive(bool month[12])
{
	for (int i = 4; i < 12; i++)
	{
		long long sum = 0;

		for (int j = i; j > i - 5; j--) sum += (month[j] ? s : d);

		if (sum >= 0) return false;
	}

	return true;
}

int main()
{
	while (cin >> s >> d)
	{
		d *= -1;

		maximum = per = 0;

		for (int bitmask = 4095; bitmask >= 0; bitmask--)
		{
			int temp = bitmask;

			bool month[12];

			for (int i = 0; i < 12; i++)
			{
				month[i] = (temp % 2);

				temp /= 2;
			}

			if (mustNegetive(month))
			{
				per = 0;

				for (int i = 0; i < 12; i++) per += (month[i] ? s : d);

				maximum = max(per, maximum);
			}
		}

		if (maximum == 0) cout << "Deficit" << endl;

		else cout << maximum << endl;
	}
}