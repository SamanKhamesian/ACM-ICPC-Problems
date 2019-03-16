#include <iostream>
#include<string>
#include <queue>

using namespace std;

int main()
{
	int test = 1;

	queue<string> dir;

	int m, n, a, b;

	cin >> test;

	while (test != 0)
	{
		cin >> m >> n;

		for (int i = 0; i < test; i++)
		{
			cin >> a >> b;

			a -= m;

			b -= n;

			if (a > 0 && b > 0)
			{
				dir.push("NE");
			}

			else if (a > 0 && b < 0)
			{
				dir.push("SE");
			}

			else if (a < 0 && b > 0)
			{
				dir.push("NO");
			}

			else if (a < 0 && b < 0)
			{
				dir.push("SO");
			}

			else if (a == 0 || b == 0)
			{
				dir.push("divisa");
			}
		}

		cin >> test;
	}

	while (!dir.empty())
	{
		cout << dir.front() << endl;

		dir.pop();
	}
}