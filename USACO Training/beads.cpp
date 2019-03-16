#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	bool turn;

	char beat;

	int n, counter = 0, max = 0;

	string neck, copy;

	fin >> n;

	fin >> neck;

	neck += neck;

	for (int i = 0; i < n; i++)
	{
		beat = neck[i];

		turn = true;

		for (int j = i; j < i + n; j++)
		{
			if (beat == 'w' && neck[j] != 'w')
			{
				beat = neck[j];
			}

			if (beat == neck[j] || neck[j] == 'w')
			{
				counter++;
			}

			else
			{
				if (turn)
				{
					beat = neck[j];

					counter++;

					turn = false;
				}

				else
				{
					break;
				}
			}
		}

		if (counter > max)
		{
			max = counter;
		}

		counter = 0;
	}

	fout << max << endl;
}