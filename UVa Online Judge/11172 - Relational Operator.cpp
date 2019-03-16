#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int number, a, b;

	queue<char> op;

	cin >> number;

	for (int i = 0; i < number; i++)
	{
		cin >> a >> b;

		if (a > b)
		{
			op.push('>');
		}

		else if (a < b)
		{
			op.push('<');
		}

		else if (a == b)
		{
			op.push('=');
		}
	}

	while (!op.empty())
	{
		cout << op.front() << endl;

		op.pop();
	}
}