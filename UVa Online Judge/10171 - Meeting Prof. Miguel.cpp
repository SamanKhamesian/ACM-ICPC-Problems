#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

#define MAX 27
#define INF 1e8 + 7

ofstream fout("f.out");

int mapY[MAX][MAX];
int mapO[MAX][MAX];

void initilaize()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			mapY[i][j] = mapO[i][j] = (i == j) ? 0 : INF;
		}
	}
}

void setMap(char a, char b, char x, char y, int w)
{
	if (a == 'Y')
	{
		if (b == 'U')
		{
			mapY[x - 'A'][y - 'A'] = w;
		}

		else if (b == 'B')
		{
			mapY[x - 'A'][y - 'A'] = w;
			mapY[y - 'A'][x - 'A'] = w;
		}
	}

	else if (a == 'M')
	{
		if (b == 'U')
		{
			mapO[x - 'A'][y - 'A'] = w;
		}

		else if (b == 'B')
		{
			mapO[x - 'A'][y - 'A'] = w;
			mapO[y - 'A'][x - 'A'] = w;
		}
	}
}

int main()
{
	int n;

	while (cin >> n, n != 0)
	{
		int w;
		char a, b, x, y;

		initilaize();

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> x >> y >> w;

			setMap(a, b, x, y, w);
		}

		for (int i = 0; i < MAX; i++)
		{
			mapO[i][i] = mapY[i][i] = 0;
		}

		for (int k = 0; k < MAX; k++)
		{
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					mapY[i][j] = min(mapY[i][j], mapY[i][k] + mapY[k][j]);
					mapO[i][j] = min(mapO[i][j], mapO[i][k] + mapO[k][j]);
				}
			}
		}

		int ans = INF;
		vector <char> places;

		char s, e;

		cin >> s >> e;

		for (int i = 0; i < MAX; i++)
		{
			if (mapY[s - 'A'][i] != INF && mapO[e - 'A'][i] != INF)
			{
				if (mapY[s - 'A'][i] + mapO[e - 'A'][i] < ans)
				{
					ans = mapY[s - 'A'][i] + mapO[e - 'A'][i];
				}
			}
		}

		if (ans == INF) cout << "You will never meet." << endl;

		else 
		{
			cout << ans;

			for (int i = 0; i < MAX; i++)
			{
				if (ans == mapY[s - 'A'][i] + mapO[e - 'A'][i])
				{
					cout << " " << char(i + 'A');
				}
			}

			cout << endl;
		}
	}
}