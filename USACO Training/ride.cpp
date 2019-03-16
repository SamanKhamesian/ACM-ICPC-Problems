#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	int comet = 1;

	int group = 1;

	string input1;

	string input2;

	fin >> input1;

	fin >> input2;

	for (int i = 0; input1[i] != '\0'; i++)
	{
		comet *= (int)input1[i] - 64;

	}

	for (int i = 0; input2[i] != '\0'; i++)
	{
		group *= (int)input2[i] - 64;
	}

	comet = comet % 47;

	group = group % 47;

	if (comet == group)
	{
		fout << "GO\n";
	}

	else
	{
		fout << "STAY\n";
	}

	return 0;
}