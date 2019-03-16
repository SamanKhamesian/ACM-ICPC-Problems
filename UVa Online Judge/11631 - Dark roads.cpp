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

int n, m, sum = 0;
int parent[MAX], sz[MAX];

ofstream fout("f.out");

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
	sum = 0;

	memset(sz, 1, sizeof sz);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	while (!pq.empty())
	{
		pq.pop();
	}
}

int mst()
{
	int ans = 0, how = 0;

	while (how != n - 1)
	{
		pair < pair <int, int>, int > temp = pq.top();

		if (!merge(temp.first)) 
		{
			ans += temp.second;

			how++;
		}

		pq.pop();
	}

	return ans;
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

			sum += w;

			pq.push(make_pair(make_pair(x, y), w));
		}

		cout << sum - mst() << endl;
	}
}