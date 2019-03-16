#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

string name;

int parent[5005];

char line[10000];

queue <int> childs;

vector <string> names;

map <string, int> match;

vector <vector<int> > graph;

int scenario = 1, P, N, edge, v, w, step, pointer, len;

void bfs(int start)
{
	for (int i = 0; i < 5005; i++)
	{
		parent[i] = 6000;
	}

	parent[start] = 0;

	childs.push(start);

	while (!childs.empty())
	{
		int head = childs.front();

		childs.pop();

		for (unsigned int i = 0; i < graph[head].size(); i++)
		{
			if (parent[graph[head][i]] == 6000)
			{
				parent[graph[head][i]] = parent[head] + 1;

				childs.push(graph[head][i]);
			}
		}
	}
}

void makeNames()
{
	len = strlen(line);

	pointer = 0;

	while (pointer < len)
	{
		name = "";

		while (pointer < len && line[pointer] == ' ')
		{
			pointer++;
		}

		if (pointer >= len)
		{
			break;
		}

		while (line[pointer] != ',')
		{
			name += line[pointer++];
		}

		name += line[pointer++];

		while (line[pointer] != ',' && line[pointer] != ':')
		{
			name += line[pointer++];
		}

		names.push_back(name);

		if (pointer >= len || line[pointer] == ':')
		{
			break;
		}

		pointer++;
	}
}

void makeGraph()
{
	for (unsigned int i = 0; i < names.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < names.size(); j++)
		{
			if (match[names[i]] == 0)
			{
				match[names[i]] = edge;

				v = edge;

				edge++;
			}

			else
			{
				v = match[names[i]];
			}

			if (match[names[j]] == 0)
			{
				match[names[j]] = edge;

				w = edge;

				edge++;
			}

			else
			{
				w = match[names[j]];
			}

			graph[v].push_back(w);

			graph[w].push_back(v);
		}

	}
}

int main()
{
	cin >> step;

	while (step--)
	{
		graph.resize(5005);

		cin >> P >> N;

		edge = 1;

		cin.get();

		while (P--)
		{
			cin.getline(line,100000);

			makeNames();

			makeGraph();

			names.clear();
		}

		bfs(match["Erdos, P."]);

		cout << "Scenario " << scenario << endl;

		while (N--)
		{
			cin.getline(line,100000);

			if (parent[match[line]] != 6000)
			{
				cout << line << " " << parent[match[line]] << endl;
			}

			else
			{
				cout << line << " infinity" << endl;
			}
		}

		scenario++;

		match.clear();

		graph.clear();
	}
}