#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

int t, n;
vector<int> parent, sz;
vector < pair<double, double> > point;

class comparator
{
public:

	bool operator()(pair<double, pair<int,int>> &x, pair<double, pair<int,int>> &y)
	{
		return x.first > y.first;
	}
};

priority_queue <pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, comparator> pq;

void initialize()
{
	point.clear();
	parent.clear();
	sz.clear();

	sz.resize(n, 1);
	parent.resize(n);

	for (int i = 0; i < n; i++)
		parent[i] = i;
}

double dist(double a, double b, double c, double d)
{
	return sqrt(((a - c)*(a - c)) + ((b - d)*(b - d)));
}

void makeGraph()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i != j)
			{
				pq.push({ dist(point[i].first, point[i].second, point[j].first, point[j].second), {i, j} });
			}
		}
	}
}

int find(int x)
{
	if (x == parent[x])
	{
		return parent[x];
	}

	else
	{
		return parent[x] = find(parent[x]);
	}
}

bool merge(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if(px == py)
	{
		return false;
	}

	else
	{
		if(sz[px] < sz[py])
		{
			swap(px, py);
		}

		parent[py] = px;

		sz[px] += sz[py];

		return true;
	}
}

double mst()
{
	double how = 0;
	int count = 0;

	while (!pq.empty())
	{
		pair< double, pair<int, int> > top = pq.top();

		pq.pop();

		if(count < n - 1 && merge(top.second.first, top.second.second))
		{
			how += top.first;

			count++;
		}
	}

	return how;
}

int main()
{
	bool ok = false;

	cin >> t;

	while (t--)
	{
		cin >> n;

		initialize();

		for (int i = 0; i < n; i++)
		{
			double x, y;

			cin >> x >> y;

			point.push_back({ x,y });
		}

		makeGraph();

		if (!ok) ok = true;

		else cout << endl;

		printf("%.2f\n", mst());
	}
}