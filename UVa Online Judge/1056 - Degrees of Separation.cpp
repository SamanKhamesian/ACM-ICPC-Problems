#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int n, q, v, w, degree = 0;

string firstName, secondName;

vector<vector<int>> list;

queue<int> endof;

vector <bool> marked;

void dfs(int b)
{
	marked[b] = true;

	for (int i = 0; i < list[b].size(); i++)
	{
		if (!marked[list[b][i]])
		{
			dfs(list[b][i]);
		}
	}
}

int bfs(int a)
{
	int m = 0, counter = 0;

	vector<int> parent;

	vector<bool> visited;

	queue<int> bfsq;

	parent.resize(n + 1);

	visited.resize(n + 1);

	visited[a] = true;

	bfsq.push(a);

	parent[a] = -1;

	while (!bfsq.empty())
	{
		int temp = bfsq.front();

		bfsq.pop();

		for (int i = 0; i < list[temp].size(); i++)
		{
			if (!visited[list[temp][i]])
			{
				bfsq.push(list[temp][i]);

				visited[list[temp][i]] = true;

				parent[list[temp][i]] = temp;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int j = i;

		while (parent[j] != -1)
		{
			counter++;

			j = parent[j];
		}

		m = max(counter, m);

		counter = 0;
	}

	return m;
}

int main()
{
	int test = 0;

	bool ok = true;

	cin >> n >> q;

	while (n != 0 && q != 0)
	{
		test++;

		map <string, int> names;

		list.resize(n + 1);

		marked.resize(n + 1);

		int index = 1;

		for (int i = 1; i <= q; i++)
		{
			cin >> firstName >> secondName;

			if (names[firstName] == 0)
			{
				v = index++;

				names[firstName] = v;
			}

			else
			{
				v = names[firstName];
			}

			if (names[secondName] == 0)
			{
				w = index++;

				names[secondName] = w;
			}

			else
			{
				w = names[secondName];
			}

			list[v].push_back(w);

			list[w].push_back(v);
		}

		dfs(1);

		for (int i = 1; i <= n; i++)
		{
			if (!marked[i])
			{
				ok = false;
			}
		}

		if (ok)
		{
			for (int i = 1; i <= n; i++)
			{
				degree = max(bfs(i), degree);
			}

			endof.push(degree);
		}

		else
		{
			endof.push(-1);
		}
		
		for (int i = 1; i <= n; i++)
		{
			list.pop_back();

			marked[i] = false;
		}

		cin >> n >> q;

		ok = true;

		degree = 0;
	}

	for (int i = 1; i <= test ; i++)
	{
		cout << "Network " << i << ": ";

		if (endof.front() != -1)
		{
			cout << endof.front() << endl << endl;
		}

		else
		{
			cout << "DISCONNECTED" << endl << endl;
		}

		endof.pop();
	}
}