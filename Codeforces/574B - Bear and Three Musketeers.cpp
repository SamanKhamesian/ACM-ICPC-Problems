#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int degree = 1000000000;

vector<vector<int>> list;

bool isConnected[4001][4001];

int triangle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (list[i].size() >= 2)
		{
			for (int j = 0; j < list[i].size() - 1; j++)
			{
				for (int k = j + 1; k < list[i].size(); k++)
				{
					if (isConnected[list[i][k]][list[i][j]])
					{
						int z, x, y;

						z = list[i].size() - 2;

						x = list[list[i][j]].size() - 2;

						y = list[list[i][k]].size() - 2;

						degree = min(degree, (x + y + z));
					}
				}
			}
		}
	}

	if (degree == 1000000000)
	{
		return -1;
	}

	else
	{
		return degree;
	}
}

int main()
{
	int n, q, v, w;

	cin >> n >> q;

	list.resize(n + 1);

	for (int i = 0; i < q; i++)
	{
		cin >> v >> w;

		list[v].push_back(w);

		list[w].push_back(v);

		isConnected[v][w] = isConnected[w][v] = true;
	}

	cout << triangle(n) << endl;
}