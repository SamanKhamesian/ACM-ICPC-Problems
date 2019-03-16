#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 100010

int parent[SIZE];

vector< pair < pair< int, int >, int > > list;

int findParent(int vertex)
{
    if (vertex == parent[vertex])
    {
        return parent[vertex];
    }

    else
    {
        return parent[vertex] = findParent(parent[vertex]);
    }
}

bool merge(pair<int, int> pairVertex)
{
    if (findParent(pairVertex.first) == findParent(pairVertex.second))
    {
        return true;
    }

    else
    {
        parent[findParent(pairVertex.second)] = findParent(pairVertex.first);

        return false;
    }
}

class comparator
{
public:

    bool operator()(pair<pair<int, int>, int> &child1, pair<pair<int, int>, int> &child2)
    {
        return child1.second > child2.second;
    }
};

priority_queue< pair< pair< int, int >, int >, vector< pair< pair< int, int >, int > >, comparator> pq;

int MST()
{
    int result = -1;

    while (!pq.empty())
    {
        pair<pair<int, int>, int> head = pq.top();

        if (!merge(make_pair(head.first.first , head.first.second)))
        {
            result = max(result, head.second);
        }

        pq.pop();
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, w, x, y, t;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        list.resize(m);

        memset(parent, 0, SIZE);

        while (!pq.empty())
        {
            pq.pop();
        }

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> w;

            list[i] = (make_pair(make_pair(x, y), w));

            pq.push(list[i]);
        }

        cout << MST() << endl;
    }
}