#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <fstream>
#include <queue>

using namespace std;

ofstream fout("f.out");

#define SIZE 1005

double r, ansR1, ansR2;
int n, test, t = 1, state = 0;

vector <pair <int, int> > points;

int parent[SIZE], sz[SIZE];

int findParent(int vertex)
{
	if (vertex == parent[vertex])
	{
		return parent[vertex];
	}

	else
	{
		return parent[vertex] = findParent(parent[vertex]);
	}
}

bool merge(pair<int, int> pairVertex)
{
	int x = pairVertex.first;

	int y = pairVertex.second;

	if (findParent(x) == findParent(y))
	{
		return true;
	}

	else
	{
		x = findParent(x);

		y = findParent(y);

		if (sz[x] < sz[y])
		{
			swap(x, y);
		}

		parent[y] = x;

		sz[x] += sz[y];

		return false;
	}
}

class comparator
{
public:

	bool operator()(pair<pair<int, int>, double> &child1, pair<pair<int, int>, double> &child2)
	{
		return child1.second > child2.second;
	}
};

priority_queue< pair< pair< int, int >, double >, vector< pair< pair< int, int >, double > >, comparator> pq;

void MST()
{
	int how = 0;

	while (!pq.empty() && how < n - 1)
	{
		pair <pair <int, int>, double> head = pq.top();

		if (!merge(make_pair(head.first.first, head.first.second)))
		{
			how++;

			double temp = head.second;

			if (temp > r)
			{
				ansR2 += temp;

				state++;
			}

			else
			{
				ansR1 += temp;
			}
		}

		pq.pop();
	}
}

void initialize(int n)
{
	points.clear();

	points.resize(n);

	state = ansR1 = ansR2 = 0;

	while (!pq.empty())
	{
		pq.pop();
	}

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;

		sz[i] = 1;
	}
}

double cal(pair <int, int> a, pair<int, int> b)
{
	int x1, x2, y1, y2;

	x1 = a.first;
	x2 = b.first;

	y1 = a.second;
	y2 = b.second;

	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> r;

		initialize(n);

		for (int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			points[i] = make_pair(x, y);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double dis = cal(points[i], points[j]);

				pq.push(make_pair(make_pair(i, j), dis));
			}
		}

		MST();

		cout << "Case #" << t++ << ": " << state + 1 << " " << round(ansR1) << " " << round(ansR2) << endl;
	}
}