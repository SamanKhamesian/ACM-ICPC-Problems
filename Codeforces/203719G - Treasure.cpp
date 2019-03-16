#include <iostream>
#include <string>

using namespace std;

string s;

long long bracket = 0, how = 0 ,sum = 0;

int main()
{
	cin >> s;

	for (int i = 0; s[i] ; i++)
	{
		if (s[i] == '(')
		{
			bracket++;

			sum++;
		}

		else
		{
			bracket--;

			if (sum)
			{
				sum--;
			}

			if (bracket < 0)
			{
				cout << -1;

				return 0;
			}

			if (s[i] == '#')
			{
				how++;

				sum = 0;
			}
		}
	}

	if (sum > 0)
	{
		cout << -1;

		return 0;
	}

	for (int i = 0; i < how - 1; i++)
	{
		cout << 1 << endl;
	}

	cout << ++bracket << endl;
}