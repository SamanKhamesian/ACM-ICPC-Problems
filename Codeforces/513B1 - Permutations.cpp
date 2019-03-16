#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int m, n, h = 0;

int minimum(string s, int start, int end)
{
	int result = 10000000;

	for (int i = start; i <= end; i++)
	{
		if (result > ((int)(s[i] - '0')))
		{
			result = ((int)(s[i] - '0'));
		}
	}

	return result;
}

void per(string s, int start, int size)
{
	static int counter = 0;

	if (start == size)
	{
		int bound = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = i; j < m; j++)
			{
				bound += minimum(s, i, j);
			}
		}

		if (bound == h)
		{
			counter++;

			if (counter == n)
			{
				for (int i = 0; i < m; i++)
				{
					cout << s[i] << " ";
				}
			}
		}
	}

	else
	{
		for (int i = start; i <= size; i++)
		{
			char c = s[i];

			s[i] = s[start];

			s[start] = c;

			per(s, start + 1, size);
		}
	}
}

int main()
{
	cin >> m >> n;

	string s = "";

	for (int i = 0; i < m; i++)
	{
		s = s + (char)(i + 49);

		h += ((m - i) * (i + 1));
	}

	per(s, 0, m - 1);

	cin.get();

	return 0;
}