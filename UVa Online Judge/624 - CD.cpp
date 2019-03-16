#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
	int N, t, bitmask = 0, ans = 0, ones;

	while (cin >> N >> t)
	{
		bitmask = ans = ones = 0;

		int* value = new int[t];

		for (int i = 0; i < t; i++)
		{
			cin >> value[i];
		}

		for (int i = 0; i < (1 << t); i++)
		{
			int index = 0, temp = i, sum = 0, how = 0;

			while (temp)
			{
				if (temp % 2)
				{
					how++;
					sum += value[t - index - 1];
				}

				index++;

				temp /= 2;
			}

			if ((sum > ans && sum <= N) || (sum == ans && how >= ones && sum <= N))
			{
				bitmask = i;

				ones = how;

				ans = sum;
			}
		}

		int index = 0;
		stack<int> s;

		while (bitmask)
		{
			if (bitmask % 2)
			{
				s.push(value[t - index - 1]);
			}

			index++;

			bitmask /= 2;
		}

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}

		cout << "sum:" << ans << endl;
	}
}