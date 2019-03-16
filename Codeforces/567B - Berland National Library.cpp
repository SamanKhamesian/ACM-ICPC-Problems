#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string x;
	int n, c = 0, e = 0;

	cin >> n;

	string* y = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		if (x == "+" && c > e)
		{
			e++;
		}

		else if (x == "+")
		{
			e++;
			c++;
		}

		if (x == "-")
		{

		}
	}

	cout << c << endl;
}