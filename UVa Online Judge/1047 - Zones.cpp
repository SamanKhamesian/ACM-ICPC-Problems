#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

bool first = false;

int n, m, howData, howAns, testCase = 1;

vector <bool> visit;
vector <set <int> > datas;
vector <int> ans, tow, combination, number;

int inclusion_exclusion(vector <int> ones)
{
	int sum = 0;

	visit.clear();
	visit.resize(howData, false);

	for (int i = 0; i < (int)ones.size(); i++)
	{
		int cond = ones[i];

		sum += tow[cond];

		for (int j = 0; j < howData; j++)
		{
			if (!visit[j])
			{
				bool found = binary_search(datas[j].begin(), datas[j].end(), cond);

				if (found)
				{
					visit[j] = true;

					sum += number[j];
				}
			}
		}
	}

	return sum;
}

void go(int offset, int k)
{
	if (k == 0)
	{
		int per = inclusion_exclusion(combination);

		if (per > howAns)
		{
			howAns = per;

			ans = combination;
		}

		return;
	}

	for (int i = offset; i <= tow.size() - k; ++i)
	{
		combination.push_back(i);

		go(i + 1, k - 1);

		combination.pop_back();
	}
}

void initialize()
{
	ans.clear();

	tow.clear();
	tow.resize(n);

	combination.clear();

	howAns = 0;
}

int main()
{
	while (cin >> n >> m , n != 0 || m != 0)
	{
		initialize();

		for (int i = 0; i < n; i++)
		{
			cin >> tow[i];
		}

		cin >> howData;

		datas.clear();
		datas.resize(howData);

		number.clear();
		number.resize(howData);

		for (int i = 0; i < howData; i++)
		{
			int x, num;

			cin >> x;

			for (int j = 0; j < x; j++)
			{
				cin >> num;

				num--;

				datas[i].insert(num);
			}

			cin >> number[i];

			set <int> ::iterator it;

			for (it = datas[i].begin(); it != datas[i].end(); it++)
			{
				tow[*it] -= number[i];
			}
		}

		go(0, m);

		printf("Case Number  %d\n", testCase++);
		printf("Number of Customers: %d\n", howAns);
		printf("Locations recommended:");

		for (int i = 0; i < (int)ans.size(); i++) cout << " " << ans[i] + 1;

		cout << endl << endl;
	}
}