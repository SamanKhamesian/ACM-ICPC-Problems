#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, part;

	string bag;

	cin >> bag;

	cin >> n;

	if (bag.length() % n != 0)
	{
		cout << "NO" << endl;

		return 0;
	}

	else
	{
		part = bag.length() / n;

		for (int i = 0; i < bag.length(); i += part)
		{
			string s = bag.substr(i, part);

			string temp = s;

			reverse(s.begin(), s.end());

			if (temp != s)
			{
				cout << "NO" << endl;

				return 0;
			}
		}

		cout << "YES" << endl;

		return 0;
	}
}