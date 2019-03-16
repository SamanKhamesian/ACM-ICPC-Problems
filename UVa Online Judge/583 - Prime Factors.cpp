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

ll x;
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

int main()
{
    findPrime();

    while (cin >> x && x != 0)
    {
        factors.clear();

        if (x < 0)
        {
            factors.push_back(make_pair(-1, 1));
        }

        findFactors(abs(x));

        cout << x << " = ";

        for (int i = 0; i < factors.size(); ++i)
        {
            for (int j = 0; j < factors[i].second; ++j)
            {
                if (i != 0 || j != 0)
                    cout << " x ";

                cout << factors[i].first;
            }
        }

        cout << endl;
    }
}