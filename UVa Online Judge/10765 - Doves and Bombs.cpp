#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 10010

class comparator
{

public:

	bool operator()(pair <int, int> &child1, pair <int, int> &child2)
	{
		if (child1.first == child2.first)
		{
			return child1.second > child2.second;
		}

		else
		{
			return child1.first < child2.first;
		}
	}
};

int n, m, dfsCount;
int root, rootChildren;
bool visited[MAX];
vector < vector <int> > graph;
int points[MAX], num[MAX], low[MAX], parent[MAX];
priority_queue < pair <int, int>, vector < pair <int, int> >, comparator > pq;

void initilalize(int n)
{
	rootChildren = root = dfsCount = 0;

	graph.clear();
	graph.resize(n);

	while (!pq.empty()) pq.pop();

	memset(num, 0, sizeof num);
	memset(low, 0, sizeof low);
	memset(points, 0, sizeof points);
	memset(parent, -1, sizeof parent);
	memset(visited, 0, sizeof visited);
}

void dfs(int start)
{
	visited[start] = true;

	low[start] = num[start] = dfsCount++;

	for (int i = 0; i < graph[start].size(); i++)
	{
		int child = graph[start][i];

		if (!visited[child])
		{
			parent[child] = start;

			if (start == root) rootChildren++;

			dfs(child);

			if (low[child] >= num[start]) points[start]++;

			low[start] = min(low[start], low[child]);
		}

		else if (child != parent[start]) low[start] = min(low[start], num[child]);
	}
}

int main()
{
	while (cin >> n >> m, n != 0 || m != 0)
	{
		initilalize(n);

		int x, y;

		while (cin >> x >> y, x != -1 || y != -1)
		{
			graph[x].push_back(y);

			graph[y].push_back(x);
		}

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				root = i;

				dfs(i);

				points[i] = (rootChildren > 1);
			}
		}

		for (int i = 0; i < n; i++)
		{
			pq.push(make_pair(points[i] + 1, i));
		}

		for (int i = 0; i < m; i++)
		{
			cout << pq.top().second << " " << pq.top().first << endl;

			pq.pop();
		}

		cout << endl;
	}
}