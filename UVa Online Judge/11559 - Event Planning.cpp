#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool ok;
int n, h, b, w, total;

class comparator
{
public:

	bool operator()(pair<int, int> &x, pair<int, int> &y)
	{
		return x.second > y.second;
	}
};

struct hotel
{
	int price;

	vector<int> beds;
};

int main()
{
	while (cin >> n >> b >> h >> w)
	{
		ok = false;

		total = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

		vector <hotel> hotels;

		for (int i = 0; i < h; i++)
		{
			hotel temp;

			cin >> temp.price;

			pq.push(make_pair(i, temp.price));

			for (int j = 0; j < w; j++)
			{
				int empty;

				cin >> empty;

				temp.beds.push_back(empty);
			}

			hotels.push_back(temp);
		}

		while (!pq.empty() && !ok)
		{
			int ind = pq.top().first;

			int person = pq.top().second;
			
			pq.pop();

			for (int i = 0; i < w; i++)
			{
				if (hotels[ind].beds[i] >= n && b >= person * n)
				{
					ok = true;

					total = person * n;

					break;
				}
			}
		}

		if (ok) cout << total << endl;

		else cout << "stay home" << endl;
	}
}