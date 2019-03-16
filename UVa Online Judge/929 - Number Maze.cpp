#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1005

int n, m, t;
int dis[MAX][MAX];
int maze[MAX][MAX];

char disX[4] = { 0, 1, 0, -1 };
char disY[4] = { 1, 0, -1, 0 };

class comparator
{
public:

	bool operator()(pair<pair<int, int>, int> &child1, pair<pair<int, int>, int> &child2)
	{
		return child1.second > child2.second;
	}
};

void initialize()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			dis[i][j] = INT_MAX;

			maze[i][j] = INT_MAX;
		}
	}
}

int travel()
{
	dis[1][1] = 0;

	priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comparator>pq;

	pq.push(make_pair(make_pair(1, 1), dis[1][1]));

	while (!pq.empty())
	{
		pair<pair<int, int>, int> head = pq.top();

		pq.pop();

		int i = head.first.first;
		int j = head.first.second;

		int headDis = head.second;

		for (int k = 0; k < 4; k++)
		{
			int x = i + disX[k];
			int y = j + disY[k];

			if (maze[x][y] != INT_MAX)
			{
				if (maze[x][y] + headDis < dis[x][y])
				{
					dis[x][y] = headDis + maze[x][y];

					pq.push(make_pair(make_pair(x, y), dis[x][y]));
				}
			}
		}
	}

	return dis[n][m] + maze[1][1];
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		initialize();

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> maze[i][j];
			}
		}

		cout << travel() << endl;
	}
}