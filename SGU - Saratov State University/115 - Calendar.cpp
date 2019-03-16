#include <iostream>
#include <algorithm>

using namespace std;

int cal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	int n, m, sum = 0;

	cin >> n >> m;

	if (m > 12 || n > cal[m - 1])
	{
		cout << "Impossible" << endl;
	}

	else
	{
		for (int i = 0; i < m - 1; i++)
		{
			sum += cal[i];
		}

		sum += n;

		if (sum % 7 ? cout << sum % 7 : cout << 7);
	}
}