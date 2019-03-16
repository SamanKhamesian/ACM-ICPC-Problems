#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n, q, m = 0;

	stack<int> start;

	stack<int> end;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> q;

		start.push(q);
	}

	m = start.top();

	start.pop();

	end.push(0);

	while (!start.empty())
	{
		q = start.top();

		if (q <= m)
		{
			end.push(m + 1 - q);
		}

		else
		{
			end.push(0);
		}
		
		m = max(q, m);

		start.pop();
	}

	while (!end.empty())
	{
		cout << end.top() << " ";

		end.pop();
	}
}