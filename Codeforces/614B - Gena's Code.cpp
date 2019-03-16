#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	bool ok = false;

	string r, s;

	long long n, count = 0;

	cin >> n;

	for (long long i = 0; i < n; i++)	{		cin >> s;		if (s[0] == '0')		{			cout << 0;			return 0;		}		else if (s[0] != '1')		{			r = s;			continue;		}		else		{			for (int i = 1; i < s.size(); i++)			{				if (s[i] != '0')				{					ok = true;					r = s;					break;				}			}			if (!ok)			{				count += (s.size() - 1);			}		}		ok = false;	}

	if (r.size() > 0)
	{
		cout << r;
	}

	else	{		cout << 1;	}

	for (long long i = 0; i < count; i++)	{		cout << 0;	}
}