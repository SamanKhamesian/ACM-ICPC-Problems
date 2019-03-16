#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int count = 0;

	string s;

	cin >> s;

	if (s == "VV" || s == "KK")
			cout << 1 << endl;

	else
	{
		if (s[0] == 'K' && s[1] == 'K')
			s[0] = 'V';

		else if (s[s.length() - 1] == 'V' && s[s.length() - 2] == 'V')
			s[s.length() - 1] = 'K';

		else
		{
			for (int i = 1; i < s.length() - 1; i++)
			{
				if (s[i - 1] == 'V' && s[i] == 'V' && s[i + 1] == 'V')
				{
					s[i] = 'K';

					break;
				}

				else if (s[i - 1] == 'K' && s[i] == 'K' && s[i + 1] == 'K')
				{
					s[i] = 'V';

					break;
				}
			}
		}

		for (int i = 1; i < s.length(); i++)
		{
			if (s[i - 1] == 'V' && s[i] == 'K') count++;
		}

		cout << count << endl;
	}
}