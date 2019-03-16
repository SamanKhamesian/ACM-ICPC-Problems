#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 1000000
typedef long long ll;
typedef vector<bool> vb;


ll n, x;
vb isPrime(MAX, true);
vector<ll> prime;

void findPrimes()
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

            prime.push_back(i);
        }
    }
}

bool cal()
{
    ll count = 1;
    bool isOn = false;

    ll p_inx = 0, p = prime[p_inx];

    while (p * p <= n)
    {
        if (n % p == 0)
        {
            ll how = 0;

            while (n % p == 0)
            {
                how++;

                n /= p;
            }

            count *= (how + 1);
        }

        p = prime[++p_inx];
    }

    if (n != 1)
    {
        count *= 2;
    }

    if (count % 2 == 1) isOn = true;

    return isOn;
}

int main()
{
    findPrimes();

    while (cin >> x && x != 0)
    {
        n = x;

        cal() ? cout << "yes" << endl : cout << "no" << endl;
    }
}