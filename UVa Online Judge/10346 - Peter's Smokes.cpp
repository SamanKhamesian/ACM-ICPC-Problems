#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> list;

	int n, m, r = 0, sum = 0;

	while (cin >> n >> m)
	{
		sum += n;

		while (n >= m)
		{
			while (n > 0)
			{
				r += n % m;

				n /= m;

				sum += n;
			}

			n = r;

			r = 0;
		}

		list.push(sum);

		sum = m = n = r = 0;
	}

	while (!list.empty())
	{
		cout << list.front() << endl;

		list.pop();
	}
}
