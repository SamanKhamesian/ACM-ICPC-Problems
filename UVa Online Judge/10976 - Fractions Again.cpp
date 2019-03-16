#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int k;

	vector <pair <int, int>> ans;

	while (cin >> k)
	{
		ans.clear();

		for (int y = k + 1; y <= 2 * k; y++)
		{
			int x = ((k * y) / (y - k));

			if ((k * y) % (y - k) == 0)
			{
				ans.push_back(make_pair(x, y));
			}
		}

		cout << (int)ans.size() << endl;

		for (int i = 0; i < (int)ans.size(); i++)
		{
			printf("1/%d = 1/%d + 1/%d\n", k, ans[i].first, ans[i].second);
		}
	}
}