#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	vector<int> a;

	for (int i = 0; i < n; i++)
	{
		int x;

		cin >> x;

		a.push_back(x);
	}

	sort(a.begin(), a.end());

	if (n == 1)
	{
		cout << a[0] << endl;
	}

	else if (n == k)
	{
		cout << a[n - 1] << endl;
	}

	else
	{
		int index =  n - (k * 2 - n) - 1;

		int result = a[n - 1];

		for (int i = 0; i <= index; i++)
		{
			result = max(result, a[i] + a[index]);

			index--;
		}

		cout << result << endl;
	}
}