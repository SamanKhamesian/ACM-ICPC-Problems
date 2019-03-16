#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int test, n, m, total;

vector <short> ans;
vector <short> color;
vector <vector <int> > graph;

void creatGraph()
{
	ans.clear();

	graph.clear();

	color.clear();

	graph.resize(n);

	color.resize(n);

	for (int i = 0; i < n; i++) color[i] = 0;

	for (int i = 0; i < m; i++)
	{
		int x, y;

		cin >> x >> y;

		x--;
		y--;

		graph[x].push_back(y);

		graph[y].push_back(x);
	}
}

void coloring(int vertex)
{
	if (vertex == n)
	{
		int black = 0;

		for (int i = 0; i < n; i++) if (color[i]) black++;

		if (black > total)
		{
			total = black;

			ans.clear();

			for (int i = 0; i < n; i++) if (color[i] == 1) ans.push_back(i + 1);
		}
	}

	else
	{
		color[vertex] = 1;

		bool beBlack = true;

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			if (color[graph[vertex][i]])
			{
				beBlack = false;

				break;
			}
		}

		if (beBlack) coloring(vertex + 1);

		color[vertex] = 0;

		coloring(vertex + 1);
	}

}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n >> m;

		creatGraph();

		total = 0;

		coloring(0);

		cout << total << endl;
		
		for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";

		cout << ans[ans.size() - 1] << endl;
	}
}