#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 10000010

typedef long long ll;
typedef vector <ll> vll;
typedef vector <bool> vb;

ll l, h, t;
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
                isPrime[j]  =false;
            }

            primes.push_back(i);
        }
    }
}

ll sumDiv(ll n)
{
    ll ans = 1;

    ll p_index = 0, p = primes[p_index];

    while (p * p <= n)
    {
        if (n % p == 0)
        {
            ll count = 0;

            while (n % p == 0)
            {
                n /= p;
                count++;
            }

            ans *= (count + 1);
        }

        p = primes[++p_index];
    }

    if (n != 1)
    {
        ans *= (2);
    }

    return ans;
}

int main()
{
    cin >> t;

    findPrimes();

    while (t--)
    {
        cin >> l >> h;

        ll sol = 0, sol_index = l;

        for (ll i = l; i <= h; ++i)
        {
            ll temp = sumDiv(i);

            if (sol < temp)
            {
                sol = temp;
                sol_index = i;
            }
        }

        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, h, sol_index, sol);
    }
}