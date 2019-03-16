#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool first = true;

	string s, copy = "";

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (first && s[i] == '0')
		{
			first = false;

			continue;
		}

		else
		{
			copy += s[i];
		}
	}

	if (first)
	{
		for (int i = 0; i < copy.size() - 1; i++)
		{
			cout << copy[i];
		}
	}

	else
	{
		cout << copy << endl;
	}
	
}