#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int n, m, test = 1;
queue <string> ans;
vector <bool> visited;
map <string, int> nam;
map <string, int> inDegree;
vector <string> names;
vector < vector <int> > graph;

int main()
{
	while (cin >> n)
	{
		names.clear();

		names.resize(n + 1);

		graph.clear();

		graph.resize(n + 1);

		visited.clear();

		visited.resize(n + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			string s;

			cin >> s;

			names[i] = s;

			nam[s] = i;

			inDegree[s] = 0;
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			string v, w;

			cin >> v >> w;

			graph[nam[v]].push_back(nam[w]);

			inDegree[w]++;
		}

		for (int i = 0; i < n; i++)
		{
			map <string, int> ::iterator it;

			for (it = inDegree.begin(); it != inDegree.end(); it++)
			{
				int number = nam[it->first];

				string child = it->first;

				if (it->second == 0 && !visited[number])
				{
					visited[number] = 1;

					ans.push(it->first);

					for (int j = 0; j < (int)graph[number].size(); j++)
					{
						inDegree[names[graph[number][j]]]--;
					}

					break;
				}
			}
		}

		cout << "Case #" << test++ << ": " << "Dilbert should drink beverages in this order:";

		while (!ans.empty())
		{
			cout << " " << ans.front();

			ans.pop();
		}

		cout << "." << endl << endl;
	}
}