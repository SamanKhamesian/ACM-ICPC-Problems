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

ll x, p, e;
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

    reverse(factors.begin(), factors.end());
}

int main()
{
    vpll a;

    findPrime();

    while (true)
    {
        string s;
        stringstream is;

        getline(cin, s);

        is << s;

        x = 1;
        a.clear();
        factors.clear();

        while (is >> p && p != 0)
        {
            is >> e;
            a.push_back(make_pair(p, e));
        }

        if (p == 0)
        {
            break;
        }

        else
        {
            for (int i = 0; i < a.size(); ++i)
            {
                for (int j = 0; j < a[i].second; ++j)
                {
                    x *= a[i].first;
                }
            }

            x -= 1;

            findFactors(x);

            for (int k = 0; k < factors.size(); ++k)
            {
                if (k != 0)
                    cout << " ";

                cout << factors[k].first << " " << factors[k].second;
            }

            cout << endl;
        }
    }
}