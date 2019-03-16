#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a[1010] = { 0 };

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int m, n, p, q, sum = 0, cash = 0;

	fin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		fin >> p >> q;

		a[p] += q;
	}

	for (int i = 0; i < 1001; i++)
	{
		while (a[i] > 0)
		{
			if (sum < n)
			{
				sum++;

				cash += i;

				a[i]--;
			}

			else
			{
				fout << cash << endl;

				return 0;
			}
		}
	}

	fout << cash << endl;

	return 0;
}