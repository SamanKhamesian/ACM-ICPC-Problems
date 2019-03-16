#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <fstream>

using namespace std;

#define MAX 200010

ofstream fout("f.out");

int n, m;
int parent[MAX], sz[MAX];
vector <int> ans;

class comparator
{
public:

	bool operator()(pair<pair<int, int>, int> &child1, pair<pair<int, int>, int> &child2)
	{
		return child1.second > child2.second;
	}
};

priority_queue< pair< pair< int, int >, int >, vector< pair< pair< int, int >, int > >, comparator> pq;

int findParent(int x)
{
	if (x == parent[x]) return parent[x];

	else return parent[x] = findParent(parent[x]);
}

bool merge(pair <int, int> edge)
{
	int x = edge.first;

	int y = edge.second;

	if (findParent(x) == findParent(y)) return true;

	else
	{
		x = findParent(x);

		y = findParent(y);

		if (sz[x] < sz[y]) swap(x, y);

		parent[y] = x;

		sz[x] += sz[y];

		return false;
	}
}

void initialize(int n)
{
	ans.clear();

	memset(sz, 1, sizeof sz);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
}

void mst()
{
	while (!pq.empty())
	{
		pair < pair <int, int>, int > temp = pq.top();

		if (merge(temp.first))
		{
			ans.push_back(temp.second);
		}

		pq.pop();
	}
}

int main()
{
	while (cin >> n >> m, n != 0 || m != 0)
	{
		initialize(n);

		for (int i = 0; i < m; i++)
		{
			int x, y, w;

			cin >> x >> y >> w;

			pq.push(make_pair(make_pair(x, y), w));
		}

		mst();

		sort(ans.begin(), ans.end());

		if (ans.size() == 0) cout << "forest" << endl;

		else
		{
			cout << ans[0];

			for (int i = 1; i < ans.size(); i++)
			{
				cout << " " << ans[i];
			}

			cout << endl;
		}
	}
}