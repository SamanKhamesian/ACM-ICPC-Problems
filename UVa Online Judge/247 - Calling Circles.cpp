#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n, m, dfsCount, num, t = 1;

stack <int> points;
vector <bool> visited;
map <int, string> numbs;
map <string, int> names;
vector <int> dfs_num, dfs_low;
vector < vector <int> > people;
vector < vector <string> > ans;

void show()
{
	if (t != 1) cout << endl;

	cout << "Calling circles for data set " << t++ << ":" << endl;

	for (int i = (int)ans.size() - 1; i >= 0; i--)
	{
		vector <string> temp = ans[i];

		if (temp.size() != 0)
		{
			cout << temp[temp.size() - 1];

			for (int j = temp.size() - 2; j >= 0; j--)
			{
				cout << ", " << temp[j];
			}

			cout << endl;
		}
	}
}

void initialize(int n)
{
	num = dfsCount = 1;
	numbs.clear();
	names.clear();

	visited.clear();
	visited.resize(n , 0);

	dfs_low.clear();
	dfs_low.resize(n, -1);

	dfs_num.clear();
	dfs_num.resize(n, -1);

	people.clear();
	people.resize(n);

	ans.clear();
	ans.resize(n);
}

void dfs(int start)
{
	visited[start] = true;

	points.push(start);

	dfs_low[start] = dfs_num[start] = dfsCount++;

	for (int i = 0; i < (int)people[start].size(); i++)
	{
		int child = people[start][i];

		if (dfs_num[child] == -1) dfs(child);

		if (visited[child]) dfs_low[start] = min(dfs_low[child], dfs_low[start]);
	}

	if (dfs_num[start] == dfs_low[start])
	{
		vector <string> subAns;

		while (points.top() != start)
		{
			subAns.push_back(numbs[points.top()]);

			visited[points.top()] = false;

			points.pop();
		}

		subAns.push_back(numbs[points.top()]);

		visited[points.top()] = false;

		points.pop();

		ans.push_back(subAns);
	}
}

int main()
{
	while (cin >> n >> m, n != 0 || m != 0)
	{
		initialize(n + 1);

		for (int i = 0; i < m; i++)
		{
			string v, w;

			cin >> v >> w;

			if (!names[v]) names[v] = num++;
			if (!names[w]) names[w] = num++;

			numbs[names[v]] = v;
			numbs[names[w]] = w;

			people[names[v]].push_back(names[w]);
		}

		for (int i = 1; i <= n; i++)
		{
			if (dfs_num[i] == -1) dfs(i);
		}

		show();
	}
}