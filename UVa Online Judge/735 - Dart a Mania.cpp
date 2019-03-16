#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <vector>

using namespace std;

int num;
set<int> save;
set<int> scores;
set<int> ::iterator it1;
set<int> ::iterator it2;
set<int> ::iterator it3;

void initializing()
{
	save.clear();
	scores.clear();

	for (int i = 0; i <= 20; i++)
	{
		scores.insert(i * 1);
		scores.insert(i * 2);
		scores.insert(i * 3);
	}
	scores.insert(50);
}

void addPer(int a, int b, int c)
{
	save.insert((a * 10000) + (b * 100) + c);
	save.insert((a * 10000) + (c * 100) + b);
	save.insert((b * 10000) + (a * 100) + c);
	save.insert((b * 10000) + (c * 100) + a);
	save.insert((c * 10000) + (a * 100) + b);
	save.insert((c * 10000) + (b * 100) + a);
}

void showResult(int num, int c, int p)
{
	if (p == 0)
	{
		printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", num);
	}

	else
	{
		printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", num, c);
		printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", num, p);
	}

	printf("**********************************************************************\n");
}

int main()
{
	ios::sync_with_stdio(0);

	initializing();

	cin >> num;

	while (num > 0)
	{
		save.clear();

		int p = 0, c = 0;

		if (num > 180)
		{
			showResult(num, c, p);
		}

		else
		{
			for (it1 = scores.begin(); it1 != scores.end(); it1++)
			{
				for (it2 = scores.begin(); it2 != scores.end(); it2++)
				{
					for (it3 = scores.begin(); it3 != scores.end(); it3++)
					{
						if (*it1 + *it2 + *it3 == num)
						{
							p++;

							int temp = (((*it1 + 25) * 10000) + ((*it2 + 25) * 100) + (*it3 + 25));

							if (save.find(temp) == save.end())
							{
								c++;

								addPer(*it1 + 25, *it2 + 25, *it3 + 25);
							}
						}
					}
				}
			}

			showResult(num, c, p);
		}

		cin >> num;
	}

	printf("END OF OUTPUT\n");
}