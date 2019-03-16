#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;

	long long sum = 0;

	cin >> n;

	map<int,int> list;

	for (int i = 1; i <= n; i++)
	{
		int x;

		cin >> x;

		list[x] = i;
	}

	for (int i = 1; i < n; i++)
	{
		sum += (abs(list[i + 1] - list[i]));
	}

	cout << sum << endl;
}