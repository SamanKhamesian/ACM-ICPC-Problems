#include <iostream>
#include <queue>

using namespace std;

int n, m;

int sovle(int n, int m)
{
	if (n > m)
	{
		swap(n, m);
	}

	if (n == 1)
	{
		return m;
	}

	if (n == 2)
	{
		return m / 4 * 4 + (m % 4 == 1 ? 2 : (m % 4 >= 2 ? 4 : 0));
	}

	return (n * m + 1) / 2;
}

int main()
{
	cin >> m >> n;

	queue<int> result;

	queue<int> rows;

	queue<int> columns;

	while (m != 0 || n != 0)
	{
		int r = 0;

		rows.push(m);

		columns.push(n);

		r = sovle(n, m);

		result.push(r);

		cin >> m >> n;
	}

	while (!result.empty())
	{
		cout << result.front() << " knights may be placed on a " << rows.front() << " row " << columns.front() << " column board." << endl;

		result.pop();

		rows.pop();

		columns.pop();
	}
}



