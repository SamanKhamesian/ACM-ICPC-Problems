#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>

using namespace std;

int v, e, ans = 0;
vector <short> guarded;
vector< vector <int> > town;

ofstream fout("f.out");

int bfs(int start)
{
	int b = 0, w = 0;

	queue<int> q;

	q.push(start);

	guarded[start] = 0;

	while (!q.empty())
	{
		int top = q.front();

		guarded[top] ? w++ : b++;

		q.pop();

		for (int i = 0; i < town[top].size(); i++)
		{
			if (guarded[town[top][i]] == -1)
			{
				guarded[town[top][i]] = !guarded[top];

				q.push(town[top][i]);
			}

			else if (guarded[town[top][i]] == guarded[top])
			{
				return -1;
			}
		}
	}

	return (w == 0) ? b : min(b, w);
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		ans = 0;

		bool notAns = true;

		cin >> v >> e;

		town.clear();
		town.resize(v);

		guarded.clear();
		guarded.resize(v, -1);

		for (int i = 0; i < e; i++)
		{
			int x, y;

			cin >> x >> y;

			town[x].push_back(y);
			town[y].push_back(x);
		}

		for (int i = 0; i < v; i++)
		{
			int temp = 0;

			if (guarded[i] == -1)
			{
				temp = bfs(i);

				if (temp == -1)
				{
					notAns = false;

					break;
				}

				else
				{
					ans += temp;
				}
			}
		}

		if (notAns)
		{
			cout << ans << endl;
		}

		else
		{
			cout << -1 << endl;
		}
	}
}