#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <vector>

using namespace std;

int main()
{
	string s;
	int test, n, m;

	cin >> test >> s;

	while (test--)
	{
		vector <string> land;

		while (cin >> s , s[0] != 'W' || s[0] != 'L')
		{
			land.push_back(s);
		}

		istringstream is(s);

		while (cin >> s , s[0] != '\n')
		{

		}
	}
}