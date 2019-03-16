#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int n, m;
map <string, int> names;
map <int, string> numes;
vector < vector<int> > graph;

void initialize()
{
	names.clear();

	graph.clear();

	graph.resize(n + 10);
}

void makeGraph()
{
	int index = 1;

	for (int i = 0; i < n; i++)
	{
		int v, w;
		string a, b;

		cin >> a >> b;

		if (names[a] == 0)
		{
			v = index++;

			names[a] = v;

			numes[v] = a;
		}

		else
		{
			v = names[a];
		}

		if (names[b] == 0)
		{
			w = index++;

			names[b] = w;

			numes[w] = b;
		}

		else
		{
			w = names[b];
		}

		graph[v].push_back(w);
		graph[w].push_back(v);
	}
}

string bfs(int start, int end)
{
	vector<int> parent(n + 10, -1);

	vector<bool> visited(n + 10, false);

	visited[start] = true;

	queue<int> q;

	q.push(start);

	while (!q.empty())
	{
		int top = q.front();

		q.pop();

		for (int i = 0; i < graph[top].size(); i++)
		{
			if (!visited[graph[top][i]])
			{
				visited[graph[top][i]] = true;

				q.push(graph[top][i]);

				parent[graph[top][i]] = top;
			}
		}
	}

	stack<char> s;

	string ans = "";

	for (int i = end; i != -1; i = parent[i])
	{
		s.push(numes[i][0]);
	}

	while (!s.empty())
	{
		ans += s.top();

		s.pop();
	}

	return ans;
}

int main()
{
	bool first = true;

	int t;

	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		initialize();

		makeGraph();

		for (int i = 0; i < m; i++)
		{
			string start, end;

			cin >> start >> end;

			cout << bfs(names[start], names[end]) << endl;
		}

		if (t != 0) cout << endl;
	}
}