#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<string, int> list;

int main()
{
	int n, size, m = 0;

	string s = "", sub = "", result = "";

	while (cin >> n >> s)
	{
		if (n >= s.length())
		{
			cout << s << endl;
		}

		else
		{
			size = s.length() - n;

			for (int i = 0; i <= size; i++)
			{
				sub = s.substr(i, n);

				list[sub]++;

				if (m < list[sub])
				{
					m = list[sub];

					result = sub;
				}
			}

			cout << result << endl;
		}

		sub = "";

		result = "";

		m = size = 0;
	}
}