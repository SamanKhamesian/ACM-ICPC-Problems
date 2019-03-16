#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

ll n, m, c = 1;
#define MAX 110

priority_queue <pair<ll, pair<ll, ll> >, vector<pair<ll, pair<ll, ll> > > > pq;

ll parent[MAX], sz[MAX];

ll find(ll x)
{
    if (x == parent[x]) return x;

    else return find(parent[x]);
}

bool merge(ll x, ll y)
{
    ll px = find(x);
    ll py = find(y);

    if (px == py)
    {
        return false;
    }

    else
    {
        if (sz[px] < sz[py])
        {
            swap(px, py);
        }

        sz[px] += sz[py];
        parent[py] = px;

        return true;
    }
}

ll maximum_spanning_tree()
{
    ll ans = -1;

    while (!pq.empty())
    {
        ll u = pq.top().second.second;
        ll v = pq.top().second.first;
        ll w = pq.top().first;

        pq.pop();

        if (merge(u, v))
        {
            ans = w;
        }
    }

    return ans;
}

void initialization()
{
    for (ll i = 0; i < MAX; ++i)
    {
        sz[i] = 1;
        parent[i] = i;
    }
}

int main()
{
    ll t;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        initialization();

        for (ll i = 0; i < m; ++i)
        {
            ll v, u, w;

            cin >> v >> u >> w;

            pq.push({w, {v, u}});
        }

        cout << "Case #" << c++ << ": " << (ll)maximum_spanning_tree() << endl;
    }
}