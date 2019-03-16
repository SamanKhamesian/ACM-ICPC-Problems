#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int n, x;

	while (cin >> n , n != 0)
	{
		vector<int> a;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			if (x > 0) a.push_back(x);
		}

		if (a.size() == 0) cout << 0;

		else
		{
			for (int i = 0; i < a.size(); i++)
			{
				cout << a[i];

				if (i != a.size() - 1) cout << " ";
			}
		}

		cout << endl;
	}
}