#include <iostream>
#include <fstream>

using namespace std;

char dre[10][10];

char ans[7][10][10];

bool accept(char array[10][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] != ans[6][i][j])
				return false;
		}
	}

	return true;
}

bool accept(int k , int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[k][i][j] != ans[6][i][j])
				return false;
		}
	}

	return true;
}

int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	int n;

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> dre[i][j];

			ans[5][i][n - 1 - j] = ans[4][i][n - 1 - j] = ans[3][n - 1 - j][i] = ans[2][n - 1 - i][n - 1 - j] = ans[1][j][n - 1 - i] = dre[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> ans[6][i][j];
		}
	}

	for (int k = 1; k < 5; k++)
	{
		if (accept(k, n))
		{
			fout << k << endl;

			return 0;
		}
	}

	char copy1[10][10];
	char copy2[10][10];
	char copy3[10][10];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			copy3[n - 1 - j][i] =copy2[n - 1 - i][n - 1 - j] = copy1[j][n - 1 - i] = ans[5][i][j];
		}
	}

	if (accept(copy1 , n) || accept(copy2 , n) || accept(copy3 , n))
	{
		fout << 5 << endl;

		return 0;
	}

	else if (accept(dre, n))
	{
		fout << 6 << endl;

		return 0;
	}

	else
	{
		fout << 7 << endl;

		return 0;
	}

}