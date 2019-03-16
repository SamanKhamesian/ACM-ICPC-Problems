#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

#define WALK 0.006
#define SUBW 0.0015
#define INFI (long double)1e9

const long double Eps = 1e-7;

struct point
{
	long double x;
	long double y;
	int label;
};

int n, query;

string junk, sep = "";

point source, goal, stop;

vector <vector <pair <int, long double> > > graph;

inline bool lessThan(long double a, long double b)
{
	return a < b - Eps;
}

class comparator
{
	public:

		bool operator()(pair<int, long double> &a, pair<int, long double> &b)
		{
			return lessThan(b.second, a.second);
		}
};

inline long double calDist(point a, point b)
{
	long double X = a.x - b.x;
	long double Y = a.y - b.y;
	return (long double)sqrt((long double)(X * X) + (long double)(Y * Y));
}


void init(vector<point> subway)
{
	graph.clear();
	graph.resize(subway.size());

	for (int i = 0; i < subway.size(); i++)
	{
		for (int j = 0; j < subway.size(); j++)
		{
			if (i == j) continue;

			if (subway[i].label == subway[j].label && abs(i - j) == 1)
			{
				graph[i].push_back({ j, SUBW * calDist(subway[i], subway[j]) });
			}

			else
			{
				graph[i].push_back({ j, WALK * calDist(subway[i], subway[j]) });
			}
		}
	}
}

long double dijkstra(int start, int dist)
{
	vector<long double> dp(dist + 1, INFI);

	dp[start] = 0;

	priority_queue<pair <int, long double>, vector <pair <int, long double> >, comparator> pq;

	pq.push({ start, dp[start] });

	while (!pq.empty())
	{
		pair<int, long double> head = pq.top();

		pq.pop();

		int u = head.first;
		
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			long double w = graph[u][i].second;

			if (lessThan(dp[u] + w, dp[v]))
			{
				dp[v] = dp[u] + w;

				pq.push({ v, dp[v] });
			}
		}
	}

	return dp[dist];
}

int main()
{
	cin >> query;

	while (query--)
	{
		vector<point> subway;

		cin >> source.x >> source.y >> goal.x >> goal.y;

		source.label = 0;

		subway.push_back(source);

		n = 1;

		while (getline(cin, junk), isdigit(cin.peek()))
		{
			while (cin >> stop.x >> stop.y, stop.x != -1)
			{
				stop.label = n;

				subway.push_back(stop);
			}

			n++;
		}

		goal.label = n;

		subway.push_back(goal);

		init(subway);

		cout << fixed << setprecision(0) << sep << dijkstra(0, subway.size() - 1) << '\n';

		sep = "\n";
	}
}