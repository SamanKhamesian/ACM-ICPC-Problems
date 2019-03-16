#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

#define MAX 500000

bool f = false;
int t, n;
string src, dest;
int src_num, dest_num;

vector<int> parent;
vector<bool> visited;
map<string, int> name;
map<int, string> reve;
vector<vector <int> > graph;

void printSol(int start, int end)
{
	if (f)
		cout << endl;

	else
		f = true;

	if(!visited[end])
	{
		cout << "No route" << endl;
	}

	else
	{
		stack<int> p;

		for (int i = end; i != -1; i = parent[i])
		{
			p.push(i);
		}

		int temp = p.top();

		p.pop();

		while (!p.empty())
		{
			int sec = p.top();

			p.pop();

			cout << reve[temp] << " " << reve[sec] << endl;

			temp = sec;
		}
	}
}

void initialize()
{
	n = 0;

	name.clear();
	reve.clear();

	graph.clear();
	graph.resize(MAX);

	visited.clear();
	visited.resize(MAX, false);
	parent.clear();
	parent.resize(MAX, 0);
	
}

void bfs(int start, int end)
{
	queue<int> q;

	q.push(start);

	visited[start] = true;
	parent[start] = -1;

	while(!q.empty())
	{
		int top = q.front();

		q.pop();

		for (int i = 0; i < graph[top].size(); i++)
		{
			int child = graph[top][i];

			if(!visited[child])
			{
				parent[child] = top;

				visited[child] = true;

				q.push(child);
			}
		}
	}

	printSol(start, end);
}

int main()
{
	while (cin >> t)
	{
		initialize();

		for (int i = 0; i < t; i++)
		{
			string v, u;
			int num_v, num_u;

			cin >> v >> u;

			num_v = name[v];
			num_u = name[u];
			
			if(name[v] == 0)
				num_v = ++n;

			if(name[u] == 0)
				num_u = ++n;

			reve[num_v] = v;
			reve[num_u] = u;

			name[v] = num_v;
			name[u] = num_u;

			graph[num_v].push_back(num_u);
			graph[num_u].push_back(num_v);
		}

		cin >> src >> dest;

		src_num = name[src];
		dest_num = name[dest];

		if (src_num == 0)
			src_num = ++n;

		if (dest_num == 0)
			dest_num = ++n;

		reve[src_num] = src;
		reve[dest_num] = dest;

		name[src] = src_num;
		name[dest] = dest_num;

		bfs(src_num, dest_num);
	}
}