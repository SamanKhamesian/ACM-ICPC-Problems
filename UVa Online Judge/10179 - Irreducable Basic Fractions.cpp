#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 10000010

typedef long long ll;
typedef vector <ll> vll;
typedef vector <bool> vb;

ll n;
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

ll eulerPhi()
{
    ll ans = n;

    ll p_index = 0, p = primes[p_index];

    while (p * p <= n)
    {
        if (n % p == 0)
        {
            ans -= (ans / p);

            while (n % p == 0)
            {
                n /= p;
            }
        }

        p = primes[++p_index];
    }

    if (n != 1)
    {
        ans -= (ans / n);
    }

    return ans;
}

int main()
{
    findPrimes();

    while (cin >> n && n != 0)
    {
        cout << eulerPhi() << endl;
    }
}