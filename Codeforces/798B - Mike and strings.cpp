#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10005

int main()
{
	int n;

	cin >> n;

	vector<string> a, b;

	for (int i = 0; i < n; i++)
	{
		string s;

		cin >> s;

		b.push_back(s);

		a.push_back(s + s);
	}

	
	int ans = MAX;

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int j = 0; j < n; j++)
		{
			if (a[j].find(b[i]) > MAX)
			{
				cout << -1 << endl;

				return 0;
			}

			count += a[j].find(b[i]);
		}

		ans = min(ans, count);
	}

	cout << ans << endl;
}