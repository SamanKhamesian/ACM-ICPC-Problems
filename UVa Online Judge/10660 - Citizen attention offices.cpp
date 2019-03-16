#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

ofstream fout("f.out");

#define MAX 1000000000

int n, test;
long long minAns;
int ans[5], town[25];

long long cal(int office, int area)
{
	long long result = 0;

	int officeX, officeY, areaX, areaY;

	officeX = office / 5;
	officeY = office % 5;

	areaX = area / 5;
	areaY = area % 5;

	result = (abs(areaX - officeX) + abs(areaY - officeY)) * town[area];

	return result;
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n;

		bool first = true;
		minAns = MAX;
		memset(ans, 0, sizeof ans);
		memset(town, 0, sizeof town);

		for (int i = 0; i < n; i++)
		{
			int x, y, pop;

			cin >> x >> y >> pop;

			town[(x * 5) + y] = pop;
		}

		for (int a = 0; a < 25; a++)
		{
			for (int b = a + 1; b < 25; b++)
			{
				for (int c = b + 1; c < 25; c++)
				{
					for (int d = c + 1; d < 25; d++)
					{
						for (int e = d + 1; e < 25; e++)
						{
							int office[5] = { a, b, c, d, e };

							long long minSum = 0;

							for (int i = 0; i < 25; i++)
							{
								if (town[i] > 0)
								{
									long long minDis = MAX;

									for (int j = 0; j < 5; j++)
									{
										minDis = min(minDis, cal(office[j], i));
									}

									minSum += minDis;
								}
							}

							if (minSum < minAns)
							{
								minAns = minSum;

								for (int k = 0; k < 5; k++)
								{
									ans[k] = office[k];
								}
							}
						}
					}
				}
			}
		}

		cout << ans[0];

		for (int i = 1; i < 5; i++)
		{
			cout << " " << ans[i];
		}

		cout << endl;
	}
}