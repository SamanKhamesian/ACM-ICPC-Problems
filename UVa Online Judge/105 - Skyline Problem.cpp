#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10005

int main()
{
	int a[MAX];

	memset(a, 0, sizeof a);

	int l, h, r;

	while (cin >> l >> h >> r)
	{
		for (int i = l; i < r; i++)
		{
			a[i] = max(a[i], h);
		}
	}

	int H = 0;

	bool flag = false;

	for (int i = 0; i < MAX; i++)
	{
		if (H != a[i])
		{
			if (flag)
			{
				cout << " ";
			}

			cout << i << " " << a[i];

			flag = true;

			H = a[i];
		}
	}

	cout << endl;
}