#include <iostream>
using namespace std;

typedef long long ll;

ll b, p, m;

inline ll multiply(ll a, ll b)
{
    return (((a % m) * (b % m)) % m);
}

ll perfect_pow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }

    else if (b == 1)
    {
        return a;
    }

    else
    {
        ll temp = perfect_pow(a, b / 2);

        if (b % 2 == 0)
        {
            return multiply(temp, temp);
        }

        else
        {
            return (multiply(multiply(temp, temp), a));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (cin >> b >> p >> m)
    {
        cout << perfect_pow(b, p) << endl;
    }
}
