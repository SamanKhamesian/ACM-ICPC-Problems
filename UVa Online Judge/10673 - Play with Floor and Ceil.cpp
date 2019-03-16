#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll c, k, x, y, d;

void extendedEuclid(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }

    extendedEuclid(b, a % b);

    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        cin >> c >> k;

        extendedEuclid(floor((double)c / k), ceil((double)c / k));

        x *= (c / d);
        y *= (c / d);

        cout << x << " " << y << endl;
    }
}