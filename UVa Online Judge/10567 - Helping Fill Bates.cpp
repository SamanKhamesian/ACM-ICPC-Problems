#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

int q;
string s;
bool notFound;
vector<int> ans;
map <char, vector <int> > myMap;

void initialize()
{
	ans.clear();
	notFound = false;

	cin >> s >> q;

	for (int i = 0; i < (int)s.size(); i++) myMap[s[i]].push_back(i);
}

int main()
{
	initialize();
	
	for (int i = 0; i < q; i++)
	{
		string query;

		cin >> query;

		ans.clear();

		int pre = 0;

		notFound = false;

		for (int j = 0; j < (int)query.size(); j++)
		{
			vector<int> temp = myMap[query[j]];

			vector<int>::iterator it = lower_bound(temp.begin(), temp.end(), pre);

			if (it != temp.end())
			{
				ans.push_back(*it);

				pre = *it + 1;
			}

			else
			{
				notFound = true;

				break;
			}
		}

		if (notFound) cout << "Not matched" << endl;

		else printf("Matched %d %d\n", ans[0], ans[ans.size() - 1]);
	}
}