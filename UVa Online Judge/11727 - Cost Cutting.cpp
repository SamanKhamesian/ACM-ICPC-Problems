#include <iostream>
#include<algorithm>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	int ar[3];

	int t, a, b, c;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> ar[0] >> ar[1] >> ar[2];

		sort(ar, ar + 3);

		q.push(ar[1]);
	}

	int counter = 1;

	while (!q.empty())
	{
		cout << "Case " <<counter<<": "<< q.front() << endl;

		counter++;

		q.pop();
	}
}