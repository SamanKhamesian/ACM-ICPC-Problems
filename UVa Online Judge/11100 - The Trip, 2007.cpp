#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n;

	bool first = false;

	while (cin >> n , n != 0)
	{
		int maximum = 0, lastInsert = 0;

		map <int, int> how;

		int* a = new int[n];

		vector< set <int> > ans;
		vector< set <int> > repeat(n + 1);

		for (int i = 0; i < n; i++)
		{
			int x;

			cin >> x;

			a[i] = x;

			how[x]++;

			maximum = max(how[x], maximum);
		}

		for (int i = 0; i < n; i++) repeat[how[a[i]]].insert(a[i]);

		ans.resize(maximum);

		for (int i = n; i >= 0; i--)
		{
			while (!repeat[i].empty())
			{
				int top = *repeat[i].begin();

				repeat[i].erase(repeat[i].begin());

				for (int j = 0; j < i; j++)
				{
					ans[lastInsert].insert(top);

					lastInsert = (lastInsert + 1) % maximum;
				}
			}
		}

		if (first) cout << endl;

		else first = true;

		cout << maximum << endl;

		for (int i = 0; i < maximum; i++)
		{
			cout << *ans[i].begin();

			ans[i].erase(ans[i].begin());

			set<int>::iterator it;

			for (it = ans[i].begin(); it != ans[i].end(); it++) cout << " " << *it;

			cout << endl;
		}
	}
}