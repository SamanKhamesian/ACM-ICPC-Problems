#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 2005

int dis[MAX][MAX];

int disX[4] = { 1, 0, -1, 0 };
int disY[4] = { 0, 1, 0, -1 };

int n, m, ans, how = 0;

bool safe(int x, int y)
{
	if (x >= 0 && y >= 0 && x <= 2000 && y <= 2000) return true;

	else return false;
}

void initialize()
{
	ans = INT_MAX;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			dis[i][j] = INT_MAX;
		}
	}
}

int main()
{
	while (cin >> n, n != 0)
	{
		initialize();

		queue < pair <int, int> > q, p;

		for (int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			dis[x][y] = 0;

			q.push(make_pair(x, y));
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			p.push(make_pair(x, y));
		}

		while (!q.empty())
		{
			pair<int, int> head = q.front();

			q.pop();

			how++;

			int x = head.first;

			int y = head.second;

			for (int i = 0; i < 4; i++)
			{
				if (safe(x + disX[i], y + disY[i]))
				{
					if (dis[x + disX[i]][y + disY[i]] > dis[x][y] + 1)
					{
						dis[x + disX[i]][y + disY[i]] = dis[x][y] + 1;

						q.push(make_pair(x + disX[i], y + disY[i]));
					}
				}
			}
		}

		while (!p.empty())
		{
			pair<int, int> head = p.front();

			p.pop();

			int x = head.first;

			int y = head.second;

			int state = dis[x][y];

			ans = min(ans, state);
		}

		cout << ans << endl;
	}
}
