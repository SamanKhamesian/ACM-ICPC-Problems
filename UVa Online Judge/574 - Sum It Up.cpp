#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

bool found = false;
int how, n, nums[20];
vector <string> ans;
bool visit[20];

ofstream fout("f.out");

string toString(int num)
{
	string s = "";
	stack <char> myStack;

	while (num != 0)
	{
		myStack.push((num % 10) + '0');

		num /= 10;
	}

	while (!myStack.empty())
	{
		s += myStack.top();

		myStack.pop();
	}

	return s;
}

int main()
{
	ios::sync_with_stdio(0);

	cin >> how >> n;

	while (how != 0 || n != 0)
	{
		found = false;

		ans.clear();

		memset(visit, 0, sizeof visit);
		memset(nums, 0, sizeof nums);

		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}

		cout << "Sums of " << how << ":" << endl;

		for (int bitmask = (1 << n); bitmask > 0 ; bitmask--)
		{
			string s = "";

			int sum = 0, temp = bitmask;

			for (int i = 0; i < n; i++)
			{
				visit[n - i - 1] = temp % 2;

				temp /= 2;
			}

			for (int i = 0; i < n; i++)
			{
				if (visit[i])
				{
					sum += nums[i];

					s += toString(nums[i]);

					s += '+';
				}
			}

			if (sum == how)
			{
				bool ok = true;

				for (int i = 0; i < (int)ans.size(); i++)
				{
					if (ans[i] == s)
					{
						ok = false;
					}
				}

				if (ok)
				{
					found = true;

					ans.push_back(s);

					s = s.substr(0, s.size() - 1);

					cout << s << endl;
				}
			}
		}

		if (!found)
		{
			cout << "NONE" << endl;
		}

		cin >> how >> n;
	}
}