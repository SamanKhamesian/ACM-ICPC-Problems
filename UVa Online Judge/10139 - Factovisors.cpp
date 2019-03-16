#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

#define MAX 10000001

typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef vector< pll > vpll;

ll n, m;
vll primes;
vpll factors;
vb isPrime(MAX, true);

void findPrime()
{
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i < MAX; ++i)
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

void findFactors(ll n)
{
    ll primes_index = 0, pf = primes[primes_index];

    while (pf * pf <= n)
    {
        ll count = 0;

        if (n % pf == 0)
        {
            while (n % pf == 0)
            {
                n /= pf;

                count++;
            }

            factors.push_back(make_pair(pf, count));
        }

        pf = primes[++primes_index];
    }

    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }
}

bool isDivide(ll x, ll y)
{
    if (y == 0) return false;

    else if (x >= y) return true;

    else
    {
        for (int i = 0; i < factors.size(); ++i)
        {
            ll how = 0;
            ll prime = factors[i].first;
            ll count = factors[i].second;

            for (ll j = prime; j <= x ; j *= prime)
            {
                how += (x / j);
            }

            if (count > how) return false;
        }

        return true;
    }
}

int main()
{
    findPrime();

    while (cin >> n >> m)
    {
        factors.clear();

        findFactors(m);

        if (isDivide(n, m))
        {
            printf("%lld divides %lld!\n", m, n);
        }

        else
        {
            printf("%lld does not divide %lld!\n", m, n);
        }
    }
}