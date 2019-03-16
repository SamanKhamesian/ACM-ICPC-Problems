#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll  x, y, d;

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
    ll a, b;

    while (cin >> a >> b)
    {
        extendedEuclid(a, b);

        cout << x << " " << y << " " << d << endl;
    }
}
