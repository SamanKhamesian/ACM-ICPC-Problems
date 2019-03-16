#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n;
	string home;
	map< pair <string, string>, int> airport;

	cin >> n >> home;

	for (int i = 0; i < n; i++)
	{
		string temp, x, y;

		cin >> temp;

		x = temp.substr(0, 3);

		y = temp.substr(5, 3);

		airport[{x, y}]++;
	}

	map<pair<string, string>, int> ::iterator it;

	bool ok = true;

	for (it = airport.begin(); it != airport.end() && ok; it++)
	{
		if (airport[{it->first.first, it->first.second}] != airport[{it->first.second, it->first.first}])
		{
			ok = false;
		}
	}

	if (ok)
		cout << "home" << endl;

	else
		cout << "contest" << endl;
}