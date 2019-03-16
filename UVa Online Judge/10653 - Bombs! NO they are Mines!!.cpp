#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1005

int n, m, sX, sY, tX, tY;
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

			if (i == 0 || j == 0 || i > n || j > m)
			{
				maze[i][j] = 0;
			}

			else
			{
				maze[i][j] = 1;
			}
		}
	}
}

int travel(int startX, int startY)
{
	dis[startX][startY] = 0;

	priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comparator>pq;

	pq.push(make_pair(make_pair(startX, startY), dis[startX][startY]));

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

			if (maze[x][y] == 1)
			{
				if (1 + headDis < dis[x][y])
				{
					dis[x][y] = headDis + 1;

					pq.push(make_pair(make_pair(x, y), dis[x][y]));
				}
			}
		}
	}

	return dis[tX][tY];
}

int main()
{
	while (cin >> n >> m, n != 0 || m != 0)
	{
		initialize();

		int how, r, c, howC;

		cin >> how;

		for (int i = 0; i < how; i++)
		{
			cin >> r >> howC;

			r++;

			for (int j = 0; j < howC; j++)
			{
				cin >> c;

				c++;

				maze[r][c] = 0;
			}
		}

		cin >> sX >> sY >> tX >> tY;

		sX++; sY++; tX++; tY++;

		cout << travel(sX, sY) << endl;
	}
}