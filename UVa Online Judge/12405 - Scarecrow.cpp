#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int test, n, t = 1, how = 0;

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n;

		cin >> s;

		how = 0;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '.')
			{
				how++;

				i += 2;
			}
		}

		printf("Case %d: %d\n",t++ , how);
	}
}