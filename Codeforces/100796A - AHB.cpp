#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string a, b, r = "";

	cin >> a;

	cin >> b;

	for (int i = 0; i < a.size(); i++)
	{
		int x, y, z;

		x = (int)(a[i] - '0');

		y = (int)(b[i] - '0');

		z = abs(x - y);

		r += (char)(z + 48);
	}

	int c = 0;

	if (r[c] == '0')
	{
		while (r[c] == '0')
		{
			c++;
		}
	}

	if (c == r.size())
	{
		cout << 0 << endl;
	}

	else
	{
		for (int i = c; i < r.size(); i++)
		{
			cout << r[i];
		}
	}
}