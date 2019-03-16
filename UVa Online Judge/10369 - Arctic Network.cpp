#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define MAX 505

int n, m, t;
int parent[MAX], sz[MAX];
vector <pair <int, int> > points;

class comparator
{
public:

	bool operator()(pair<pair<int, int>, double> &child1, pair<pair<int, int>, double> &child2)
	{
		return child1.second > child2.second;
	}
};

priority_queue< pair< pair< int, int >, double >, vector< pair< pair< int, int >, double > >, comparator> pq;

double cal(pair<int, int> a, pair<int, int> b)
{
	int x1 = a.first;
	int x2 = b.first;

	int y1 = a.second;
	int y2 = b.second;

	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

void ini()
{
	points.clear();

	for (int i = 0; i < m; i++)
	{
		parent[i] = i;

		sz[i] = 1;
	}

	while (!pq.empty())
	{
		pq.pop();
	}
}

int findParent(int v)
{
	if (v == parent[v]) return v;

	else return parent[v] = findParent(parent[v]);
}

bool merge(int x, int y)
{
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

double msf()
{
	int temp = m;

	double ans = 0;

	while (temp != n)
	{
		pair< pair <int, int>, double> head = pq.top();

		if (!merge(head.first.first, head.first.second))
		{
			temp--;

			ans = max(ans, head.second);
		}

		pq.pop();
	}

	return ans;
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		ini();

		for (int i = 0; i < m; i++)
		{
			int v, w;

			cin >> v >> w;

			points.push_back(make_pair(v, w));
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				double temp = cal(points[i], points[j]);

				pq.push(make_pair(make_pair(i, j), temp));
			}
		}

		printf("%.2f\n", msf());
	}
}