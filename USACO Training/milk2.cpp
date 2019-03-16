#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	bool time[1000001] = { false };
	int n, start, end, min = 1000000, max = 0, t1 = 0, t2 = 0, p1 = 0, p2 = 0;

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> start;
		fin >> end;

		if (start < min)
			min = start;

		if (end > max)
			max = end;

		for (int j = start; j < end ; j++)
			time[j] = true;
	}

	for (int i = min; i < max; i++)
	{
		if (time[i])
		{
			p1++;

			if (p1 > t1)
			{
				t1 = p1;
			}

			p2 = 0;
		}

		else
		{
			p2++;

			if (p2 > t2)
			{
				t2 = p2;
			}

			p1 = 0;
		}
	}

	fout << t1 << " " << t2 << endl;
}