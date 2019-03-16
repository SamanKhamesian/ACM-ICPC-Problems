#include <iostream>
using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        if (n > m) swap(n, m);

        ll d = 0;
        ll a = n * (n - 1);
        ll b = m * (m - 1);

        ll ans = 0;

        ans += (a * m) + (b * n);
        ans += 4 * (2 * (n * (n - 1) * (n - 2) / 6) + (m - n + 1) * n * (n - 1) / 2);

        cout << (ll) ans << endl;
    }
}