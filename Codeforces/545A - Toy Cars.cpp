#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> spaces;

	int n, how = 0;

	int A[100][100];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((A[i][j] == 1 || A[i][j] == 3))
				break;

			else if (j == n - 1)
			{
				how++;
				spaces.push(i + 1);
			}
		}
	}

	cout << how << endl;

	while (!spaces.empty())
	{
		cout << spaces.front() << " ";

		spaces.pop();
	}
}