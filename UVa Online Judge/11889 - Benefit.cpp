#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;

    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return b * (a / gcd(a, b));
}

int main()
{
    ll x, y, t;

    cin >> t;

    while (t--)
    {
        cin >> x >> y;

        if (y % x) cout << "NO SOLUTION" << endl;

        else
        {
            ll ans;
            ll temp = ans = y / x;

            if (y == lcm(max(ans, x), min(ans, x)))
            {
                cout << ans << endl;
            }

            else
            {
                while (y != lcm(max(ans, x), min(ans, x)))
                {
                    ans += temp;
                }

                cout << ans << endl;
            }
        }
    }
}