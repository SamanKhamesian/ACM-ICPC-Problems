
 #include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, m, counter = 0;
	char map[12][12];
	queue<int> wolvesI;
	queue<int> wolvesJ;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'W')
			{
				wolvesI.push(i);
				wolvesJ.push(j);
			}
		}
	}

	while (!wolvesI.empty())
	{
		if (map[wolvesI.front()][wolvesJ.front() + 1] == 'P')
		{
			map[wolvesI.front()][wolvesJ.front() + 1] = '.';

			counter++;
		}

		else if (map[wolvesI.front() + 1][wolvesJ.front()] == 'P')
		{
			map[wolvesI.front() + 1][wolvesJ.front()] = '.';

			counter++;
		}

		else if (map[wolvesI.front() - 1][wolvesJ.front()] == 'P')
		{
			map[wolvesI.front() - 1][wolvesJ.front()] = '.';

			counter++;
		}

		else if (map[wolvesI.front()][wolvesJ.front() - 1] == 'P')
		{
			map[wolvesI.front()][wolvesJ.front() - 1] = '.';

			counter++;
		}

		wolvesI.pop();
		wolvesJ.pop();
	}

	cout << counter << endl;
	
}