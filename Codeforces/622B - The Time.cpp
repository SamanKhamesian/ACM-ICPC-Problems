#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string changeTime(string s, int a)
{
	int hour = ((int)(s[0] - '0') * 10) + ((int)(s[1] - '0'));

	int minutes = ((int)(s[3] - '0') * 10) + ((int)(s[4] - '0'));

	int M = (hour * 60) + minutes;

	M += a;

	hour = (M / 60) % 24;

	minutes = M % 60;

	s[0] = ((char)((hour / 10) + 48));
	s[1] = ((char)((hour % 10) + 48));
	s[3] = ((char)((minutes / 10) + 48));
	s[4] = ((char)((minutes % 10) + 48));

	return s;
}

int main()
{
	int add;

	string realTime;

	cin >> realTime;

	cin >> add;

	cout << changeTime(realTime, add) << endl;
}