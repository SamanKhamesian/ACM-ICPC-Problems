#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, two = 1, r = 0, copy = 0, how = 0;

	cin >> a;

	copy = a;

	while (copy != r)
	{
		while (two * 2 <= a)
			two *= 2;

		how++;

		r += two;

		a -= two;

		two = 1;
	}

	cout << how << endl;
}