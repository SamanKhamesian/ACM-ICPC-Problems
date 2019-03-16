#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int n, counter;
string ans;
double minimum;
double dist[10][10];
vector < pair < int, int>> points;

void show()
{
	cout << "**********************************************************" << endl;
	cout << "Network #" << counter << endl;

	for (int i = 1; i < n; i++)
	{
		int pre = (int)ans[i - 1] - 48;
		int cur = (int)ans[i] - 48;

		pair<int, int> p1 = points[pre];
		pair<int, int> p2 = points[cur];

		double distance = dist[pre][cur];

		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", p1.first, p1.second, p2.first, p2.second, distance);
	}

	printf("Number of feet of cable required is %.2lf.\n", minimum);

	counter++;
}

void per(string s, int start, int size)
{
	static int counter = 0;

	if (start == size)
	{
		counter++;

		double temp = 0.0;
		string answer = s;

		for (int i = 1; i < n; i++)
		{
			int pre = (int)s[i - 1] - 48;
			int cur = (int)s[i] - 48;

			temp += dist[pre][cur];
		}

		if (temp < minimum)
		{
			minimum = temp;

			ans = answer;
		}
	}

	else
	{
		for (int i = start; i <= size; i++)
		{
			char c = s[i];

			s[i] = s[start];

			s[start] = c;

			per(s, start + 1, size);
		}
	}
}

void initilize()
{
	ans = "";

	minimum = 99999999.9;

	memset(dist, 0, sizeof dist);

	string s = "0123456789";

	s = s.substr(0, n);

	points.clear();

	for (int i = 0; i < n; i++)
	{
		int x, y;

		cin >> x >> y;

		points.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x1, x2, y1, y2;

			x1 = points[i].first;
			y1 = points[i].second;

			x2 = points[j].first;
			y2 = points[j].second;

			dist[i][j] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + 16.00;
		}
	}

	per(s, 0, n - 1);

	show();
}

int main()
{
	counter = 1;

	cin >> n;

	while (n != 0)
	{
		initilize();

		cin >> n;
	}
}