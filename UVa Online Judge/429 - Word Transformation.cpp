#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;

int test;
string s, t;
vector <int> dis;
vector <string> dic;
map <string, int> nums;
vector <vector <int> > graph;

int bfs(int start, int dist)
{
	dis[start] = 0;

	queue<int> p;

	p.push(start);

	while (!p.empty())
	{
		int head = p.front();

		p.pop();

		for (int i = 0; i < graph[head].size(); i++)
		{
			int child = graph[head][i];

			if (dis[head] + 1 < dis[child])
			{
				dis[child] = dis[head] + 1;

				p.push(child);
			}
		}
	}

	return dis[dist];
}

bool canTrans(string a, string b)
{
	int how = 0;

	for (int i = 0; i < (int)min(a.size(), b.size()); i++) if (a[i] != b[i]) how++;

	if (how == 1 && a.size() == b.size()) return true;

	else return false;
}

void ini(int n)
{
	graph.clear();

	graph.resize(n);
}

int main()
{
	cin >> test;

	while (test--)
	{
		string word = "";

		dic.clear();

		nums.clear();

		while (cin >> word, word[0] != '*')
		{
			nums[word] = dic.size();

			dic.push_back(word);
		}

		ini(dic.size());

		for (int i = 0; i < dic.size(); i++)
		{
			for (int j = i + 1; j < dic.size(); j++)
			{
				if (canTrans(dic[i], dic[j]))
				{
					graph[i].push_back(j);

					graph[j].push_back(i);
				}
			}
		}

		string line;

		size_t pos;

		getline(cin, line);

		getline(cin, line);

		while (line != "")
		{
			pos = line.find(" ");

			s = line.substr(0, pos);

			t = line.substr(pos + 1, line.size());

			dis.clear();

			dis.resize(dic.size(), INT_MAX);

			cout << s << " " << t << " " << bfs(nums[s], nums[t]) << endl;

			if (!getline(cin, line))
				break;
		}

		if (test != 0) cout << endl;
	}
}