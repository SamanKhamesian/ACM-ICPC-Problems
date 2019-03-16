#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 10000010

typedef long long ll;
typedef vector <ll> vll;
typedef vector <bool> vb;

ll s;
int c = 1;
vb isPrime(MAX, true);
vll primes;

void findPrimes()
{
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i < MAX; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}

ll sumDiv(ll n)
{
    ll ans = 1;

    ll p_inx = 0, p = primes[p_inx];

    while (p * p <= n)
    {
        if (n % p == 0)
        {
            ll how = 0;

            while (n % p == 0)
            {
                n /= p;

                how++;
            }

            ans *= ((ll)(pow((double)p, how + 1.0) - 1) / (p - 1));
        }

        p = primes[++p_inx];
    }

    if (n != 1)
    {
        ans *= ((ll)(pow((double)n, 2.0) - 1) / (n - 1));
    }

    return ans;
}

int main()
{
    findPrimes();

    while (cin >> s && s != 0)
    {
        bool ok = false;

        ll num = -1;

        for (ll i = s; i > 0 && !ok; i--)
        {
            if (sumDiv(i) == s)
            {
                ok = true;
                num = i;
            }
        }

        cout << "Case " << c++ << ": " << num << endl;
    }
}
