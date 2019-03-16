#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;

	while (cin >> n >> m, n != 0 || m != 0)
	{
		bool found = true;
		long long sum = 0;
		vector<long long> dragons(n, 0);
		vector<long long> knights(m, 0);

		for (int i = 0; i < n; i++) cin >> dragons[i];
		for (int i = 0; i < m; i++) cin >> knights[i];

		if (n > m) cout << "Loowater is doomed!" << endl;

		else
		{
			sort(knights.begin(), knights.end());

			for (int i = 0; i < n; i++)
			{
				int ind = lower_bound(knights.begin(), knights.end(), dragons[i]) - knights.begin();

				if (ind == knights.size())
				{
					found = false;

					break;
				}

				else
				{
					sum += knights[ind];

					knights.erase(knights.begin() + ind);
				}
			}

			if (found) cout << sum << endl;

			else cout << "Loowater is doomed!" << endl;
		}
	}
}
