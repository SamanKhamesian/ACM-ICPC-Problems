#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include <stack>

using namespace std;

stack<char> st;

bool check(string s)
{
	string copy;

	int size = s.length();

	for (int i = 0; i < size; i++)
	{
		copy += s[size - 1 - i];
	}

	if (copy == s)
	{
		return true;
	}

	else
	{
		return false;
	}
}

string change(int a , int b)
{
	int r = 0;

	string s = "";

	while (a != 0)
	{
		r = a % b;

		st.push(char(r + 48));

		a /= b;
	}

	while (!st.empty())
	{
		s += st.top();

		st.pop();
	}

	return s;
}

int  main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int bound, number, two = 0;

	fin >> bound >> number;

	vector<int> end;

	for (int i = number + 1; bound > 0; i++)
	{
		two = 0;

		for (int j = 2; j <= 10 ; j++)
		{
			string ss;

			ss = change(i, j);

			if (check(ss))
			{
				two++;

				if (two == 2)
				{
					bound--;

					two = 0;

					end.push_back(i);

					break;
				}
			}
		}
	}

	for (int i = 0; i < end.size(); i++)
	{
		fout << end[i] << endl;
	}
}