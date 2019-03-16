#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int n, minimum;

int dist[30][30];
vector< pair <int, int> > points;

void per(string s, int start, int size)
{
	static int counter = 0;

	if (start == size)
	{
		counter++;

		int temp = 0;

		for (int i = 1; i < n + 1; i++)
		{
			int pre = (int)(s[i - 1] - 'a');
			int cur = (int)(s[i] - 'a');

			temp += dist[pre][cur];
		}

		temp += dist[(int)(s[0] - 'a')][(int)(s[n] - 'a')];

		if (temp < minimum)
		{
			minimum = temp;
		}
	}

	else
	{
		for (int i = start; i <= size; i++)
		{
			char c = s[i];

			s[i] = s[start];

			s[start] = c;

			per(s, start + 1, size);
		}
	}
}

int main()
{
	int t, sizeX, sizeY;

	cin >> t;

	while (t--)
	{
		cin >> sizeX >> sizeY;

		int x0, y0;

		cin >> x0 >> y0;

		points.clear();

		points.push_back(make_pair(x0, y0));

		cin >> n;

		string s = "abcdefghijklmnopqrstuvwxyz";

		s = s.substr(0, n + 1);

		for (int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			points.push_back(make_pair(x, y));
		}

		memset(dist, 0, sizeof 0);

		minimum = 99999999;

		for (int i = 0; i < n + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				int x1, y1, x2, y2;

				x1 = points[i].first;
				y1 = points[i].second;

				x2 = points[j].first;
				y2 = points[j].second;

				dist[i][j] = (abs)(x1 - x2) + (abs)(y1 - y2);
			}
		}

		per(s, 0, n);

		printf("The shortest path has length %d\n", minimum);
	}
}