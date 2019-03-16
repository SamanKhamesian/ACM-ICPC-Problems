#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int n;

string victim, replaced;

set <string> people;

void print()
{
	for (set<string> ::iterator i = people.begin(); i != people.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;
}

int main()
{
	cin >> victim >> replaced;

	people.insert(victim);

	people.insert(replaced);

	print();

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> victim >> replaced;

		people.erase(victim);

		people.insert(replaced);

		print();
	}
}