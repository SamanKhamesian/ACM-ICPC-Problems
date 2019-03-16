#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int n, m = 0;

	string s;

	cin >> n;

	map<string,int> room ;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		room[s]++;

		m = max(m, room[s]);
	}

	cout << m << endl;
}