#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int t;

	cin >> t;

	bool first = true;

	while (t--)
	{
		if (!first)

			cout << '\n';
		else

			first = false;

		int d;

		cin >> d;

		map < pair < int, int >, string > marker;
		map < pair < int, int >, string >::iterator it;

		for (int i = 0; i < d; i++)
		{
			string name;

			int low, high;

			cin >> name >> low >> high;

			marker[make_pair(low, high)] = name;
		}

		int q;

		cin >> q;

		while (q--)
		{
			int p;

			cin >> p;

			string ans = "UNDETERMINED";

			for (it = marker.begin(); it != marker.end(); it++)
			{
				if (p >= it->first.first && p <= it->first.second)
				{
					if (ans != "UNDETERMINED")
					{
						ans = "UNDETERMINED";

						break;
					}

					else
					{
						ans = it->second;
					}
				}
			}

			cout << ans << endl;
		}
	}
}