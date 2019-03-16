#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int total, m, who;
	int friends = 0;
	char name[16];

	fin >> friends;

	char members[12][16];
	int money[12] = { 0 };

	for (int i = 0; i < friends; i++)
	{
		fin >> members[i];
	}

	for (int i = 0; i < friends; i++)
	{
		fin >> name;

		fin >> total >> who;

		if (who != 0)
		{
			for (int j = 0; j < friends; j++)
			{
				if (strcmp(members[j], name) == 0)
				{
					money[j] -= total;

					m = total / who;

					money[j] += (total - m * who);

					break;
				}
			}
		}
		
		for (int k = 0; k < who; k++)
		{
			fin >> name;

			for (int p = 0; p < friends; p++)
			{
				if (strcmp(members[p], name) == 0)
				{
					money[p] += m;

					break;
				}
			}
		}
	}

	for (int i = 0; i < friends; i++)
	{
		fout << members[i] << " " << money[i] << endl;
	}

	return 0;
}