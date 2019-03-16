#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, groups = 0;

vector< vector< int > > list;

queue<int> out;

void searchOnes()
{
	bool ok = false;

	for (int i = 1; i <= n; i++)
	{
		if (list[i].size() == 1)
		{
			out.push(i);

			ok = true;
		}
	}

	while (!out.empty())
	{
		int up = out.front();

		if (list[up].size() != 0)
		{
			int index = list[up][0];

			list[up].erase(list[up].begin() + 0);

			list[index].erase(std::remove(list[index].begin(), list[index].end(), up), list[index].end());
		}

		out.pop();
	}

	if (ok)
	{
		groups++;
	}

	else
	{
		cout << groups << endl;

		exit(0);
	}
}

int main()
{
	cin >> n >> m;

	list.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int x, y;

		cin >> x >> y;

		list[x].push_back(y);

		list[y].push_back(x);
	}

	while (true)
	{
		searchOnes();
	}
}