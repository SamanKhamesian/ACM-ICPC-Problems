#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 105
#define oo INT_MAX

int n, m, q, t = 1;
int parent[MAX], sz[MAX];
int temp[MAX][MAX];

class comparator
{

public:

	bool operator()(pair <pair <int, int>, int> &x, pair <pair <int, int>, int> &y)
	{
		return x.second > y.second;
	}
};

priority_queue <pair <pair<int, int>, int>, vector <pair <pair <int, int>, int> >, comparator> pq;

int findP(int v)
{
	if (v == parent[v]) return parent[v];

	else return parent[v] = findP(parent[v]);
}

bool merge(pair<int, int> a)
{
	int x = a.first;

	int y = a.second;

	if (findP(x) == findP(y)) return true;

	else
	{
		x = findP(x);

		y = findP(y);

		if (sz[x] < sz[y]) swap(x, y);

		parent[y] = x;

		sz[x] += sz[y];

		return false;
	}
}

void mst()
{
	while (!pq.empty())
	{
		pair <pair <int, int>, int> head = pq.top();

		if (!merge(head.first))
		{
			temp[head.first.first][head.first.second] = head.second;

			temp[head.first.second][head.first.first] = head.second;
		}

		pq.pop();
	}
}


void initialize(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;

		sz[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = oo;
		}
	}
}

int main()
{
	while (cin >> n >> m >> q, n != 0 || m != 0 || q != 0)
	{
		initialize(n);

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			x--; y--;

			pq.push(make_pair(make_pair(x, y), w));
		}

		mst();

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					temp[i][j] = min(temp[i][j], max(temp[i][k], temp[k][j]));
				}
			}
		}

		if (t > 1) cout << endl;

		cout << "Case #" << t++ << endl;

		for (int i = 0; i < q; i++)
		{
			int x, y;

			cin >> x >> y;

			x--; y--;

			if (temp[x][y] != oo) cout << temp[x][y] << endl;

			else cout << "no path" << endl;
		}
	}
}