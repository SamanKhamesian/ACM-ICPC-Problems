#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int test, t = 1, ans = 0, howSmall = 0;

	cin >> test;

	while (test--)
	{
		howSmall = ans = 0;

		long long n, d;

		cin >> n >> d;

		map <int, char> rock;

		vector<int> numbers;

		numbers.push_back(0);

		rock[0] = 'B';

		for (int i = 0; i < n; i++)
		{
			int temp;

			string s;

			cin >> s;

			temp = stoi(s.substr(2));

			rock[temp] = (char)s[0];

			numbers.push_back(temp);
		}

		numbers.push_back(d);

		rock[d] = 'B';

		for (int i = 0; i < 2; i++)
		{
			int pre = 0, howSmall = 0;

			for (int j = 1; j < numbers.size(); j++)
			{
				char mod = rock[numbers[j]];

				if (mod == 'B')
				{
					ans = max(numbers[j] - pre, ans);

					pre = numbers[j];
				}

				else if (mod == 'S')
				{
					if ((howSmall % 2) == i)
					{
						ans = max(numbers[j] - pre, ans);

						pre = numbers[j];
					}

					howSmall++;
				}
			}
		}

		cout << "Case " << t++ << ": " << ans << endl;
	}
}