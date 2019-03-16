#include <iostream>

using namespace std;

int main()
{
	int n, how = 0, i = 0;

	cin >> n;

	if (n == 0)
	{
		cout << 1 << endl;
	}

	else
	{
		for (i = 5; how < n; i += 5)
		{
			int temp = i, go = 0;

			while (temp % 5 == 0)
			{
				temp /= 5;

				go++;
			}

			how += go;
		}

		if (how == n)
		{
			cout << i - 5 << endl;
		}

		else
		{
			cout << "No solution" << endl;
		}
	}
}