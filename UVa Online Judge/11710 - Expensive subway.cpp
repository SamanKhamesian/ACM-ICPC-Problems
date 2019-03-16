#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define MAX 500

int n, m, counter = 0;

bool visited[MAX];
map <string, int> names;
int parent[MAX], sz[MAX];
vector <pair <int, pair <int, int> > > edges;

int find(int x)
{
	if (x == parent[x]) return x;

	else return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px == py) return false;

	else
	{
		if (sz[px] < sz[py]) swap(px, py);

		sz[px] += sz[py];

		parent[py] = px;

		return true;
	}
}

int kruskal()
{
	int ans = 0;
	int how = 0;

	for (int i = 0; i < edges.size() && how < n; i++)
	{
		int w = edges[i].first;

		if (merge(edges[i].second.first, edges[i].second.second))
		{
			visited[edges[i].second.first] = true;
			visited[edges[i].second.second] = true;

			ans += w;

			how++;
		}
	}
	
	return how == n - 1 ? ans : -1;
}

void initilize()
{
	counter = 0;

	names.clear();

	edges.clear();

	for (int i = 0; i < MAX; i++)
	{
		sz[i] = 1;

		visited[i] = false;

		parent[i] = i;
	}
}

int main()
{
	while (cin >> n >> m , n != 0 || m != 0)
	{
		initilize();

		for (int i = 0; i < n; i++)
		{
			string station;

			cin >> station;

			names[station] = counter++;
		}

		for (int i = 0; i < m; i++)
		{
			int w;

			string v, u;

			cin >> v >> u >> w;

			edges.push_back({ w, { names[v], names[u] } });
		}

		string nop;

		cin >> nop;

		sort(edges.begin(), edges.end());

		int ans = kruskal();

		if (ans == -1) cout << "Impossible" << endl;

		else cout << ans << endl;
	}
}