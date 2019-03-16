#include <iostream>
using namespace std;

typedef long long ll;

#define M 1000000000

int main()
{
    ll n, m, ans = 1;

    while (cin >> n >> m)
    {
        ans = 1;

        for (ll i = n; i >= n - m + 1 ; i--)
        {
            ans *= i;

            while (ans % 10 == 0)
            {
                ans /= 10;
            }

            ans = ans % M;
        }

        cout << ans % 10 << endl;
    }
}