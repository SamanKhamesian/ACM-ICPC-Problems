#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define REM 1000000007

int main()
{
	long long m, sum = 1, div = 1;

	vector<int> pi(200002);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x;

		cin >> x;

		pi[x]++;
	}
}