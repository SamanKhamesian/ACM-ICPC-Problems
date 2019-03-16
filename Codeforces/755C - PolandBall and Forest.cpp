#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>

using namespace std;

vector<int> parent;
vector<int> sz;

void initialize(int n)
{
	parent.resize(n);
	sz.resize(n);

	for (int i = 0; i < n; i++)
	{
		sz[i] = 1;
		parent[i] = i;
	}
}

int find(int x)
{
	if (x == parent[x])
		return x;

	else 
		return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY)
	{
		if (sz[parentX] < sz[parentY])
			swap(parentX, parentY);

		parent[parentY] = parent[parentX];

		sz[parentX] += sz[parentY];
	}
}

int main()
{
	int n, far;

	cin >> n;

	initialize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> far;

		merge(i, far);
	}

	set<int> ans;

	for (int i = 1; i <= n; i++)
	{
		ans.insert(find(i));
	}

	cout << ans.size() << endl;
}