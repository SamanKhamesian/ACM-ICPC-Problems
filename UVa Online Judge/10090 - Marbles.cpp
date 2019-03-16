#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll n, cx, cy, x, y, d;

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
    while (cin >> n && n != 0)
    {
        ll a, b, ans;

        cin >> cx >> a;
        cin >> cy >> b;

        extendedEuclid(a, b);

        if (n % d != 0)
        {
            cout << "failed" << endl;
        }

        else
        {
            long long nx, ny, ansx, ansy;

            x *= (n / d);
            y *= (n / d);

            b /= d;
            a /= d;

            nx = ceil(-(double) x / b);
            ny = floor((double) y / a);

            if (nx > ny) cout << "failed" << endl;

            else
            {
                if (((x + (nx * b)) * cx) + ((y - (nx * a)) * cy) < ((x + (ny * b)) * cx) + ((y - (ny * a)) * cy))
                {
                    ansx = x + (nx * b);
                    ansy = y - (nx * a);
                }

                else
                {
                    ansx = x + (ny * b);
                    ansy = y - (ny * a);
                }

                cout << ansx << " " << ansy << endl;
            }
        }
    }
}
