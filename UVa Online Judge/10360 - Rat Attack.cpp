#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct point
{
	int x;
	int y;
	int population;
};

int ansX, ansY, ansPo;
int TC, n, d, maximum;
vector < point > rats;
int killed[1200][1200];

int main()
{
	cin >> TC;

	while (TC--)
	{
		cin >> d;

		cin >> n;

		rats.clear();

		maximum = 0;

		ansX = ansY = ansPo = 0;

		for (int i = 0; i < 1200; i++)
		{
			for (int j = 0; j < 1200; j++)
			{
				killed[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			point newRat;

			int x, y, population;

			cin >> x >> y >> population;

			x += 55;
			y += 55;

			newRat.x = x;
			newRat.y = y;
			newRat.population = population;

			rats.push_back(newRat);
		}

		for (int k = 0; k < (int)rats.size(); k++)
		{
			int x, y, pop;

			x = rats[k].x;
			y = rats[k].y;
			pop = rats[k].population;

			for (int i = -d; i <= d; i++)
			{
				for (int j = -d; j <= d; j++)
				{
					killed[i + x][j + y] += pop;
				}
			}
		}

		for (int i = 55; i < 1080 ; i++)
		{
			for (int j = 55; j < 1080; j++)
			{
				if (killed[i][j] > ansPo)
				{
					ansX = i - 55;
					ansY = j - 55;
					ansPo = killed[i][j];
				}
			}
		}

		cout << ansX << " " << ansY << " " << ansPo << endl;
	}

	return 0;
}
