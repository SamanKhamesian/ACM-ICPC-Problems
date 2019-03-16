#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int how[7] = { 0 };

	int n, year = 1900, week = 1, day = 1, month = 0, goal;

	fin >> n;

	goal = 1900 + n - 1;

	for (int y = year; y <= goal ; y++)
	{
		for (int m = month; m <= 11; m++)
		{
			if (m == 1)
			{
				if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
				{
					for (int d = day; d <= 29; d++)
					{
						if (d == 13)
						{
							how[week]++;
						}

						week++;

						if (week == 7)
						{
							week = 0;
						}
					}
				}

				else
				{
					for (int d = day; d <= 28; d++)
					{
						if (d == 13)
						{
							how[week]++;
						}

						week++;

						if (week == 7)
						{
							week = 0;
						}
					}
				}
			}

			else if (m == 0 || m == 2 || m == 4 || m == 6 || m == 7 || m == 9 || m == 11)
			{
				for (int d = day; d <= 31; d++)
				{
					if (d == 13)
					{
						how[week]++;
					}

					week++;

					if (week == 7)
					{
						week = 0;
					}
				}
			}

			else
			{
				for (int d = day; d <= 30; d++)
				{
					if (d == 13)
					{
						how[week]++;
					}

					week++;

					if (week == 7)
					{
						week = 0;
					}
				}
			}
		}
	}

	fout << how[6];

	for (int i = 0; i < 6; i++)
	{
		fout << " " << how[i];
	}

	fout << endl;
}