#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <set>

using namespace std;

#define MAX 110
#define INF -1

bool start = false;
int childRoot, root, d = 0, c = 1, n, m;
int parent[MAX], low_time[MAX], enter_time[MAX];

vector<string> f;
vector<bool> points;
map <string, int> names;
vector<string> in;
vector <vector<int> > graph;

void initialize()
{
    d = 0;

    for (int i = 0; i < MAX; ++i)
    {
        parent[i] = INF;
        enter_time[i] = INF;
        low_time[i] = 0;
    }

    names.clear();
    in.clear();
    f.clear();

    graph.clear();
    graph.resize((unsigned)n);

    points.clear();
    points.resize((unsigned)n, false);
}

void findCutVertex(int v)
{
    enter_time[v] = low_time[v] = d++;

    for (int i = 0; i < graph[v].size(); ++i)
    {
        int u = graph[v][i];

        if (enter_time[u] == INF)
        {
            parent[u] = v;

            if (v == root)
            {
                childRoot++;
            }

            findCutVertex(u);

            if (low_time[u] >= enter_time[v])
            {
                points[v] = true;
            }

            low_time[v] = min(low_time[v], low_time[u]);
        }

        else if (u != parent[v])
        {
            low_time[v] = min(low_time[v], enter_time[u]);
        }
    }
}

int main()
{
    while (cin >> n && n != 0)
    {
        initialize();

        for (int i = 0; i < n; ++i)
        {
            string s;

            cin >> s;

            names[s] = i + 1;

            in.push_back(s);
        }

        cin >> m;

        for (int j = 0; j < m; ++j)
        {
            string v, u;

            cin >> v >> u;

            graph[names[v] - 1].push_back(names[u] - 1);
            graph[names[u] - 1].push_back(names[v] - 1);
        }

        for (int k = 0; k < n; ++k)
        {
            if (enter_time[k] == INF)
            {
                root = k;
                childRoot = 0;
                findCutVertex(k);
                points[k] = (childRoot > 1);
            }
        }

        int ans = 0;

        for (int l = 0; l < n; ++l)
        {
            if (points[l])
            {
                ans++;
                f.push_back(in[l]);
            }
        }

        sort(f.begin(), f.end());

        if (!start) start = true;
        else cout << endl;

        printf("City map #%d: %lu camera(s) found\n", c++, ans);

        for (int i = 0; i < f.size(); ++i)
        {
            cout << f[i] << endl;
        }
    }
}