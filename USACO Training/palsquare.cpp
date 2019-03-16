#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int b;

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

string change(int a)
{
	int r = 0;

	string s = "";

	while (a != 0)
	{
		r = a % b;

		if (r < 10)
		{
			st.push(char(r + 48));
		}

		else
		{
			st.push(char(r + 55));
		}

		a /= b;
	}

	while (!st.empty())
	{
		s += st.top();

		st.pop();
	}

	return s;
}

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	fin >> b;

	string p = "";

	vector<string> final;

	vector<string> mirror;

	for (int i = 1; i <= 300; i++)
	{
		p = change(i * i);

		if (check(p))
		{
			final.push_back(change(i));

			mirror.push_back(p);
		}
	}

	for (int i = 0; i < final.size(); i++)
	{
		fout << final[i] << " " << mirror[i] << endl;
	}
}