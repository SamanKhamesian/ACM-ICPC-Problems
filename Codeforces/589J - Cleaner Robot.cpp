#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

char plan[15][15];

int dirI[4] = { -1, 0, 1, 0 };
int dirJ[4] = { 0, 1, 0, -1 };

bool cleaned[15][15];

bool cleaned2D[15][15][4];

int dfsCount = 0;

int main()
{
	int count = 105;

	int direction;

	int robotI, robotJ;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> plan[i][j];

			if (plan[i][j] != '.' && plan[i][j] != '*')
			{
				robotI = i;

				robotJ = j;

				if (plan[i][j] == 'U'){ direction = 0; }

				if (plan[i][j] == 'R'){ direction = 1; }

				if (plan[i][j] == 'D'){ direction = 2; }

				if (plan[i][j] == 'L'){ direction = 3; }

				plan[i][j] = '.';

			}
		}
	}

	int i = robotI;

	int j = robotJ;

	while (!cleaned2D[i][j][direction])
	{
		if (!cleaned[i][j])
		{
			dfsCount++;
		}

		cleaned[i][j] = true;

		cleaned2D[i][j][direction] = true;

		if (plan[i + dirI[direction]][j + dirJ[direction]] == '.')
		{
			i += dirI[direction];

			j += dirJ[direction];
		}

		else
		{
			direction = (direction + 1) % 4;
		}
	}

	cout << dfsCount << endl;
}