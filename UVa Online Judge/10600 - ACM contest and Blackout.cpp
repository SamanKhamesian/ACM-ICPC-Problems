#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int test, n, m, best, secondBest;
vector <bool> choosen, finalChoosen;
vector <int> parent, sz;

ofstream fout("f.out");

class comparator
{
public:

	bool operator()(pair <pair <int, int>, int> &x, pair <pair <int, int>, int> &y)
	{
		return x.second > y.second;
	}
};

priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comparator> pq, temp;

int findParent(int v)
{
	if (parent[v] == v) return parent[v];

	else return parent[v] = findParent(parent[v]);
}

bool merge(int x, int y)
{
	int parentX = findParent(x);
	int parentY = findParent(y);

	if (parentX == parentY) return true;

	else
	{
		x = parentX;
		y = parentY;

		if (sz[x] < sz[y]) swap(x, y);

		parent[y] = x;

		sz[x] += sz[y];

		return false;
	}
}

int mst()
{
	int ans = 0, num = 0;

	while (!pq.empty())
	{
		pair<pair<int, int>, int> head = pq.top();

		int x = head.first.first;
		int y = head.first.second;

		int w = head.second;

		if (!choosen[num])
		{
			if (!merge(x, y))
			{
				ans += w;

				choosen[num] = true;
			}
		}

		num++;

		pq.pop();
	}

	return ans;
}

void initialize()
{
	choosen.clear();
	choosen.resize(m, false);

	parent.clear();
	parent.resize(n + 1);

	sz.clear();
	sz.resize(n + 1);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;

		sz[i] = 1;
	}
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		initialize();

		while (!pq.empty()) pq.pop();

		while (!temp.empty()) temp.pop();

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			pq.push(make_pair(make_pair(x, y), w));

			temp.push(make_pair(make_pair(x, y), w));
		}

		best = mst();

		secondBest = INT_MAX;

		finalChoosen = choosen;

		for (int i = 0; i < m; i++)
		{
			if (finalChoosen[i])
			{
				initialize();

				choosen[i] = true;

				pq = temp;

				int g = mst();

				if (g < secondBest && g >= best) secondBest = g;
			}
		}

		cout << best << " " << secondBest << endl;
	}
}