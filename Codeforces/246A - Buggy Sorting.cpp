#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n == 1 || n == 2)
	{
		cout << -1;
	}

	else
	{
		for (int i = 2; i <= n; i++)
		{
			cout << i << " ";
		}

		cout << 1;
	}
}