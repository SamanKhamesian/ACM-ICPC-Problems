#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n, m, v, w, big = -1, answer = -1;

	vector<set<int>> cal;

	cal.resize(100002);

	cin >> n >> m;

	int* colors = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> colors[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> v >> w;

		v--;

		w--;

		if (colors[v] != colors[w])
		{
			cal[colors[v]].insert(colors[w]);

			cal[colors[w]].insert(colors[v]);
		}
	}

	sort(colors, colors + n);

	for (int i = 0; i < n ; i++)
	{
		int size = cal[colors[i]].size();

		if (size > big)
		{
			big = size;

			answer = colors[i];
		}
	}

	cout << answer << endl;

	return 0;
}