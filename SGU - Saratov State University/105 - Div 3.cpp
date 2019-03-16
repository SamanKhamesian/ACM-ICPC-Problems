#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n % 3 == 2)
	{
		n = n / 3;

		cout << (n * 2) + 1 << endl;
	}

	else
	{
		n = n / 3;

		cout << n * 2 << endl;
	}
}