#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	int how = 0;

	string s;

	cin >> s;

	vector<char> a, b;

	for (int i = 0; i < (int)floor(s.size() / 2.0); i++)
	{
		a.push_back(s[i]);
	}

	for (int i = (int)ceil(s.size() / 2.0); i < s.size(); i++)
	{
		b.push_back(s[i]);
	}

	reverse(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) how++;
	}

	if (how == 1 || (how == 0 && (s.size() % 2) == 1)) cout << "YES" << endl;

	else cout << "NO" << endl;
}