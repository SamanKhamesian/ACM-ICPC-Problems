#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream inp("dict.txt");

	ifstream fin("namenum.in");

	ofstream fout("namenum.out");

	string name;

	bool ok = false;

	long long digits;

	string* names = new string[5010];

	long long* numbers = new long long[5010];

	for (int i = 0; i < 5000; i++)
	{
		inp >> name;

		names[i] = name;

		numbers[i] = 0;

		for (int j = 0; j < name.size(); j++)
		{
			if (name[j] == 'A' || name[j] == 'B' || name[j] == 'C')
			{
				numbers[i] = (numbers[i] * 10) + 2;
			}

			else if (name[j] == 'D' || name[j] == 'E' || name[j] == 'F')
			{
				numbers[i] = (numbers[i] * 10) + 3;
			}

			else if (name[j] == 'G' || name[j] == 'H' || name[j] == 'I')
			{
				numbers[i] = (numbers[i] * 10) + 4;
			}

			else if (name[j] == 'J' || name[j] == 'K' || name[j] == 'L')
			{
				numbers[i] = (numbers[i] * 10) + 5;
			}

			else if (name[j] == 'M' || name[j] == 'N' || name[j] == 'O')
			{
				numbers[i] = (numbers[i] * 10) + 6;
			}

			else if (name[j] == 'P' || name[j] == 'R' || name[j] == 'S')
			{
				numbers[i] = (numbers[i] * 10) + 7;
			}

			else if (name[j] == 'T' || name[j] == 'U' || name[j] == 'V')
			{
				numbers[i] = (numbers[i] * 10) + 8;
			}

			else if (name[j] == 'W' || name[j] == 'X' || name[j] == 'Y')
			{
				numbers[i] = (numbers[i] * 10) + 9;
			}
		}
	}

	fin >> digits;

	for (int i = 0; i < 5000; i++)
	{
		if (digits == numbers[i])
		{
			ok = true;

			fout << names[i] << endl;
		}
	}

	if (!ok)
	{
		fout << "NONE"<<endl;
	}
}