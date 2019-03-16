#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int n, answer, value;

vector<int> myArray;

stack  <int> sub;
vector <int> andis;
vector <int> parent;

int LIS()
{
	int length = 0;

	vector<int> t(n, 0);

	for (int i = 0; i < n; i++)
	{
		int wh = lower_bound(t.begin(), t.begin() + length, myArray[i]) - t.begin();

		t[wh] = myArray[i];

		andis[wh] = i;

		if (wh == 0)
		{
			parent[i] = -1;
		}

		else
		{
			parent[i] = andis[wh - 1];
		}

		if (length == wh)
		{
			length++;
		}
	}

	value = andis[length - 1];

	return length;
}

int main()
{
	int x = 1;

	while (cin >> x)
	{
		myArray.push_back(x);
	}

	n = myArray.size();

	parent.resize(n);
	andis.resize(n);

	answer = LIS();

	cout << answer << endl << "-" << endl;

	while (value != -1)
	{
		sub.push(myArray[value]);

		value = parent[value];
	}

	while (!sub.empty())
	{
		cout << sub.top() << endl;

		sub.pop();
	}
}