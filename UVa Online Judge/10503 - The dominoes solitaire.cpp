#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
bool found;
pair<int, int> row[20];
vector< pair <int, int> > dominos;

bool backTrack(int place, bool visit[20])
{
	if (place == n && row[place].second == row[place + 1].first)
	{
		found = true;
	}

	if (place < n)
	{
		for (int i = 0; i < m; i++)
		{
			pair<int, int> temp;
			pair<int, int> swapTemp;

			temp = dominos[i];

			swapTemp.first = temp.second;
			swapTemp.second = temp.first;

			if (!visit[i])
			{
				if (temp.first == row[place].second)
				{
					row[place + 1] = temp;

					visit[i] = true;

					backTrack(place + 1, visit);

					visit[i] = false;
				}

				else if (swapTemp.first == row[place].second)
				{
					row[place + 1] = swapTemp;

					visit[i] = true;

					backTrack(place + 1, visit);

					visit[i] = false;
				}
			}
		}
	}

	return found;
}

int main()
{
	while (cin >> n , n != 0)
	{
		cin >> m;

		found = false;
		bool visit[20];
		dominos.clear();
		memset(row, 0, sizeof row);
		memset(visit, 0, sizeof visit);

		pair<int, int> f;
		pair<int, int> l;

		cin >> f.first >> f.second;
		cin >> l.first >> l.second;

		row[0] = f;
		row[n + 1] = l;

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			dominos.push_back(make_pair(x, y));
		}

		if (n == 0)
		{
			if (l.first == f.second) cout << "NO" << endl;

			else cout << "YES" << endl;
		}

		else
		{
			if (backTrack(0, visit))
			{
				cout << "YES" << endl;
			}

			else
			{
				cout << "NO" << endl;
			}
		}
	}
}