#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int m, ans = 0;

	while (cin >> m)
	{
		ans = 0;

		vector < string > square;
		vector < pair < int, int > > ones;
		vector < pair < int, int > > threes;

		for (int i = 0; i < m; i++)
		{
			string temp;

			cin >> temp;

			square.push_back(temp);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (square[i][j] == '1')
				{
					ones.push_back(make_pair(i, j));
				}

				if (square[i][j] == '3')
				{
					threes.push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < (int)ones.size(); i++)
		{
			int each = 2147483647;
			int x1 = ones[i].first;
			int y1 = ones[i].second;

			for (int j = 0; j < (int)threes.size(); j++)
			{
				int x2 = threes[j].first;
				int y2 = threes[j].second;

				int temp = abs(x1 - x2) + abs(y1 - y2);

				each = min(temp, each);
			}

			ans = max(each, ans);
		}

		cout << ans << endl;
	}
}