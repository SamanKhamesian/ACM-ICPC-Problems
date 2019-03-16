#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector <long> treep;
	vector <long> treen;

	int n, po = 0, ne = 0;
	long element, apple, collect = 0;

	cin >> n;

	long positive[100000] = { 0 };
	long negetive[100000] = { 0 };

	for (int i = 0; i < n; i++)
	{
		cin >> element >> apple;

		if (element > 0)
		{
			treep.push_back(element);
			po++;
			positive[element] = apple;
		}

		else
		{
			treen.push_back(element);
			ne++;
			negetive[-1 * element] = apple;
		}
	}

	sort(treep.begin(), treep.end());

	sort(treen.begin(), treen.end());

	if (po > ne)
	{
		int counter = 0;

		while (counter < treep.size())
		{
			collect += positive[treep[counter]];

			counter++;

			if (!treen.empty())
			{
				collect += negetive[-1 * treen[treen.size() - 1]];

				treen.pop_back();
			}

			else
			{
				break;
			}
		}
	}

	else
	{
		int counter = 0;

		while (!treen.empty())
		{
			collect += negetive[-1 * treen[treen.size() - 1]];

			treen.pop_back();

			if (counter < treep.size())
			{
				collect += positive[treep[counter]];

				counter++;
			}

			else
			{
				break;
			}
		}
	}

	cout << collect;
}