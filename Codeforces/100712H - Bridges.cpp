#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define MAX 100010

int n, m;

int dis[MAX];

int num[MAX];

int low[MAX];

int parent[MAX];

bool marked[MAX];

queue<int> bfsq;

vector< vector< int > > list;

set< pair < int, int > > bridges;

int BFS(int start)
{
	int faar = -1, index = -1;

	marked[start] = true;

	bfsq.push(start);

	dis[start] = 0;

	while (!bfsq.empty())
	{
		int top = bfsq.front();

		bfsq.pop();

		if (faar <= dis[top])
		{
			faar = dis[top];

			index = top;
		}

		for (int i = 0; i < list[top].size(); i++)
		{
			if (!marked[list[top][i]])
			{
				marked[list[top][i]] = true;

				bfsq.push(list[top][i]);

				if (bridges.count(make_pair(top, list[top][i])) || bridges.count(make_pair(list[top][i], top)))
				{
					dis[list[top][i]] = dis[top] + 1;
				}

				else
				{
					dis[list[top][i]] = dis[top];
				}
			}
		}
	}

	return index;
}

void findBridges(int start, int dfsCount)
{
	marked[start] = true;

	low[start] = num[start] = dfsCount;

	for (int i = 0; i < list[start].size(); i++)
	{
		int child = list[start][i];

		if (!marked[child])
		{
			parent[child] = start;

			findBridges(child, dfsCount + 1);

			low[start] = min(low[start], low[child]);

			if (low[child] > num[start])
			{
				bridges.insert(make_pair(start, child));

				bridges.insert(make_pair(child, start));
			}
		}

		else if (child != parent[start])
		{
			low[start] = min(low[start], num[child]);
		}
	}
}

int main()
{
	int test = 0;

	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		bridges.clear();

		list.clear();

		list.resize(n + 1);

		memset(marked, 0, sizeof marked);

		memset(parent, -1, sizeof parent);

		memset(low, 0, sizeof low);

		memset(num, 0, sizeof num);

		for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			list[x].push_back(y);

			list[y].push_back(x);
		}

		findBridges(1, 0);

		memset(marked, 0, sizeof marked);

		int farNode = BFS(1);

		memset(marked, 0, sizeof marked);

		int farNode2 = BFS(farNode);

		int diam = dis[farNode2];

		cout << (int)bridges.size() / 2 - diam << endl;
	}
}