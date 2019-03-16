#include <iostream>
#include <algorithm>

using namespace std;

int t[11] = { 0, 5, 15, 30, 50, 75, 105, 140, 180, 225, 275 };

int main()
{
	int n, k;

	cin >> n >> k;

	k = 240 - k;

	for (int i = 0; i < 11; i++)
	{
		if (k == t[i])
		{
			cout << min(i, n) << endl;

			break;
		}

		else if (k < t[i])
		{
			cout << min(i - 1, n) << endl;
			
			break;
		}
	}
}