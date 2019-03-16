#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool check(int a, int b, int c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a)) return true;

	else return false;
}

int main()
{
	int n;

	bool ok = false;

	cin >> n;

	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i <= n - 3 && !ok; i++)
	{
		if (check(arr[i], arr[i + 1], arr[i + 2])) ok = true;
	}

	if (ok) cout << "YES" << endl;

	else cout << "NO" << endl;
}